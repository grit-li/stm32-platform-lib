TOP = .

include $(TOP)/Makefile.func

DIRS += cutils
DIRS += stm32-platform
DIRS += rtthread-nano
DIRS += startup

.PHONY: rebuild all clean $(DIRS)
all:
	@$(call FOREACH_EXECUTE_FUNC,$(DIRS),$@)

clean:
	@$(call FOREACH_EXECUTE_FUNC,$(DIRS),$@)

rebuild:
	@$(MAKE) clean --no-print-directory
	@$(MAKE) all --no-print-directory