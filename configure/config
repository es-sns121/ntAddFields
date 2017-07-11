
# ==============================   Qt includes and libs ======================================

QT_INCLUDE += -I$(QT_INC) -I$(QT_INC)/Qt -I$(QT_INC)/QtCore -I$(QT_INC)/QtGui 
QT_LIBRARY += -L$(QT_LIB) -lQtCore -lQtGui

# =========================   EPICS V3 and V4 includes and libs ==============================

EPICS_INCLUDE += -I$(EPICS_V3_DIR)/include                   \
				-I$(EPICS_V3_DIR)/include/compiler/gcc       \
				-I$(EPICS_V3_DIR)/include/valgrind           \
				-I$(EPICS_V3_DIR)/include/os/$(HOST_OS)      \
				-I$(EPICS_V4_DIR)/pvAccessCPP/include        \
				-I$(EPICS_V4_DIR)/pvDataCPP/include          \
				-I$(EPICS_V4_DIR)/normativeTypesCPP/include  \
				-I$(EPICS_V4_DIR)/pvaClientCPP/include       \
				-I$(EPICS_V4_DIR)/pvDatabaseCPP/include      \
				-I$(EPICS_V4_DIR)/pvCommonCPP/include

EPICS_LIBRARY += -L$(EPICS_V3_DIR)/lib/$(EPICS_HOST_ARCH) -lCom                     \
				-L$(EPICS_V4_DIR)/pvDataCPP/lib/$(EPICS_HOST_ARCH) -lpvData         \
				-L$(EPICS_V4_DIR)/pvAccessCPP/lib/$(EPICS_HOST_ARCH) -lpvAccess     \
				-L$(EPICS_V4_DIR)/pvCommonCPP/lib/$(EPICS_HOST_ARCH) -lpvMB         \
				-L$(EPICS_V4_DIR)/pvaClientCPP/lib/$(EPICS_HOST_ARCH) -lpvaClient   \
				-L$(EPICS_V4_DIR)/pvDatabaseCPP/lib/$(EPICS_HOST_ARCH) -lpvDatabase \
				-L$(EPICS_V4_DIR)/normativeTypesCPP/lib/$(EPICS_HOST_ARCH) -lnt   

INC += $(EPICS_INCLUDE) $(QT_INCLUDE)
LIB += $(EPICS_LIBRARY) $(QT_LIBRARY)

# ==========================================================================================

CPP_FLAGS = -Wall -g -lpthread -lm 

