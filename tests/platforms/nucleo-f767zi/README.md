# platforms/nucleo-f767zi

Note: It cannot be a static library, since it makes extensive use of `weak` symbols.

## OpenOCD invocation

To run the tests, invoke them via OpenOCD:

```sh
openocd \
      -c "gdb port disabled" \
      -c "tcl port disabled" \
      -c "telnet port disabled" \
      -f interface/stlink-dap.cfg \
      -c "adapter speed 5000" \
      -f target/stm32f7x.cfg \
      -c "program test.elf verify" \
      -c "arm semihosting enable" \
      -c "arm semihosting_cmdline test one two" \
      -c "reset"
```
