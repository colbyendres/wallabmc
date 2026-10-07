# Phase 4 feature fragments (local RISC-V QEMU port, not upstream)

Kconfig fragments layered on top of `boards/qemu_riscv{32,64}.conf`, which
starts from upstream's `qemu_cortex_m3` feature set (everything off). They
are **cumulative**: step N is built with fragments 1..N, in order, as a
`;`-separated `EXTRA_CONF_FILE` list. Kconfig dependencies make that order
natural (APP_WEB selects REDFISH, APP_HTTPS needs one of them,
APP_WEB_TERMINAL selects APP_WEB).

Build and test a step with `scripts/test-wallabmc-features.sh` from the
bolt-graphics root.
