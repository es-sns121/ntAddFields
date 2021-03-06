
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

// Creates a pvStructure to be added to the normative type as a nested structure.
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

// Create a pvRecord holding a modified normative type
PVRecordPtr createRecord(const string & record_name)
{
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

	PVRecordPtr pvRecord = PVRecord::create(record_name, pvStructure);

	return pvRecord;
}
