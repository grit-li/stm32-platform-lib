TOP = .
include $(TOP)/Makefile.func

TARGET = stm32-platform-test

include $(TOP)/source.in

ASM_SOURCES ?= $(filter %.s,$(SOURCES))
C_SOURCES ?= $(filter %.c,$(SOURCES))
CPP_SOURCES ?= $(filter %.cpp,$(SOURCES))

vpath
vpath %.s $(sort $(dir $(ASM_SOURCES)))
vpath %.c $(sort $(dir $(C_SOURCES)))
vpath %.cpp $(sort $(dir $(CPP_SOURCES)))

BIN_PATH := bin
OBJ_DIR := obj
OBJECT_FILE = $(notdir $(C_SOURCES:.c=.o)) $(notdir $(ASM_SOURCES:.s=.o)) $(notdir $(CPP_SOURCES:.cpp=.o))
OBJECT_FILE := $(addprefix $(OBJ_DIR)/,$(OBJECT_FILE))

.PHONY: all clean
all: $(OBJECT_FILE) Makefile | $(OBJ_DIR)
	@$(MAKE) $(BIN_PATH)/$(TARGET).elf --no-print-directory
	@$(MAKE) $(BIN_PATH)/$(TARGET).hex --no-print-directory
	@$(MAKE) $(BIN_PATH)/$(TARGET).bin --no-print-directory

clean:
	@$(RM) -rf $(OBJ_DIR)
	@$(RM) -rf $(BIN_PATH)

$(OBJ_DIR) $(BIN_PATH):
	@$(MKDIR) -p $@

$(OBJ_DIR)/%.o: %.cpp Makefile | $(OBJ_DIR)
	@$(call PRINT_COMPILE_CPP,"$<")
	@$(CXX) -E $(CXXFLAGS) $(LOCAL_CXXFLAGS) -MMD -MP -MF"$(@:%.o=%.d)" -Wa,-a,-ad,-alms=$(OBJ_DIR)/$(notdir $(<:.cpp=.lst)) $< -o $@.i
	@$(CXX) -c $(CXXFLAGS) $(LOCAL_CXXFLAGS) -MMD -MP -MF"$(@:%.o=%.d)" -Wa,-a,-ad,-alms=$(OBJ_DIR)/$(notdir $(<:.cpp=.lst)) $< -o $@

$(OBJ_DIR)/%.o: %.c Makefile | $(OBJ_DIR)
	@$(call PRINT_COMPILE_C,"$<")
	@$(ECHO) $(CC) -c $(CFLAGS) $(LOCAL_CFLAGS) -MMD -MP -MF"$(@:%.o=%.d)" -Wa,-a,-ad,-alms=$(OBJ_DIR)/$(notdir $(<:.c=.lst)) $< -o $@
	@$(CC) -E $(CFLAGS) $(LOCAL_CFLAGS) -MMD -MP -MF"$(@:%.o=%.d)" -Wa,-a,-ad,-alms=$(OBJ_DIR)/$(notdir $(<:.c=.lst)) $< -o $@.i
	@$(CC) -c $(CFLAGS) $(LOCAL_CFLAGS) -MMD -MP -MF"$(@:%.o=%.d)" -Wa,-a,-ad,-alms=$(OBJ_DIR)/$(notdir $(<:.c=.lst)) $< -o $@

$(OBJ_DIR)/%.o: %.s Makefile | $(OBJ_DIR)
	@$(call PRINT_COMPILE_ASM,"$<")
	@$(CC) -E $(ASFLAGS) $(LOCAL_ASFLAGS) -MMD -MP -MF"$(@:%.o=%.d)" -Wa,-a,-ad,-alms=$(OBJ_DIR)/$(notdir $(<:.s=.lst)) $< -o $@.i
	@$(AS) -c $(ASFLAGS) $(LOCAL_ASFLAGS) -MMD -MP -MF"$(@:%.o=%.d)" -Wa,-a,-ad,-alms=$(OBJ_DIR)/$(notdir $(<:.s=.lst)) $< -o $@

$(BIN_PATH)/$(TARGET).elf: $(OBJECT_FILE) Makefile | $(BIN_PATH)
	@$(call PRINT_COMPILE_ELF,"$(notdir $@"))
	@$(ECHO) $(CC) $(OBJECT_FILE) $(LDFLAGS) $(LOCAL_LDFLAGS) -Wl,-Map=$(BIN_PATH)/$(TARGET).map,--cref -o $@
	@$(CC) $(OBJECT_FILE) $(LDFLAGS) $(LOCAL_LDFLAGS) -Wl,-Map=$(BIN_PATH)/$(TARGET).map,--cref -o $@

$(BIN_PATH)/$(TARGET).hex: $(BIN_PATH)/$(TARGET).elf Makefile | $(BIN_PATH)
	@$(call PRINT_COMPILE_HEX,"$(notdir $@"))
	@$(OBJCOPY) -Oihex  $< $@

$(BIN_PATH)/$(TARGET).bin: $(BIN_PATH)/$(TARGET).elf Makefile | $(BIN_PATH)
	@$(call PRINT_COMPILE_BIN,"$(notdir $@"))
	@$(OBJCOPY) -Obinary -S $< $@
