
// record.h

// Header file for modified normative type record creation.

#ifndef RECORD_H
#define RECORD_H

#include <pv/pvDatabase.h>

epics::pvDatabase::PVRecordPtr createRecord(const std::string & record_name);

#endif // RECORD_H
