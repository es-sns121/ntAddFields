
// record.cpp

// Implementation file of functions defined in record.h

#include "record.h"
#include <pv/ntscalar.h>
#include <pv/standardField.h>
#include <pv/serverContext.h>

using std::cerr;
using std::string;
using namespace epics::nt;
using namespace epics::pvData;
using namespace epics::pvDatabase;

PVStructurePtr createStructure()
{
	FieldCreatePtr fieldCreate = getFieldCreate();
	PVDataCreatePtr pvDataCreate = getPVDataCreate();
	
	StructureConstPtr structure = fieldCreate->createFieldBuilder()->
		add("a_long", pvLong)->
		add("another_double", pvDouble)->
		add("are_we_having_fun_yet", pvBoolean)->
		createStructure();
	
	PVStructurePtr pvStructure = pvDataCreate->createPVStructure(structure);

	return pvStructure;
}

PVDatabasePtr create()
{
	bool result(false);
	string recordName("myRecord");
	
	PVDatabasePtr master = PVDatabase::getMaster();

	NTScalarBuilderPtr ntScalarBuilder = NTScalar::createBuilder();
	StandardFieldPtr standardField = getStandardField();

	PVStructurePtr pvStructure = ntScalarBuilder->
		value(pvDouble)->
		addAlarm()->
		addTimeStamp()->
		// ^ This will create a ntScalar structure with an alarm and time stamp field.

		// To add an optional field, first define a structure, then use add() to add the field.
		add("nested_structure", createStructure()->getField())->
		
		// Alternatively, use the StandardField builder to create a desired structure. Then request the field
		// pointer to add the field.
		add("extra_field", standardField->scalar(pvString, "value")->getField("value"))->
		
		createPVStructure();

	PVRecordPtr pvRecord = PVRecord::create(recordName, pvStructure);

	result = master->addRecord(pvRecord);
	if (!result) cerr << "Failed to add '" << recordName << "' record to the database.\n";

	return master;
}
