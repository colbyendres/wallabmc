/*
 * RISC-V QEMU virt port (local, not upstream).
 *
 * QEMU virt has no unique-ID register, so Zephyr's hwinfo falls back to the
 * weak z_impl_hwinfo_get_device_id() returning -ENOSYS, and vpd_init() (via
 * APP_BMC_UUID, selected by REDFISH) aborts main() before networking comes
 * up. Override it with a fixed per-board ID so the BMC UUID is
 * deterministic.
 */

#include <string.h>
#include <zephyr/drivers/hwinfo.h>
#include <zephyr/sys/util.h>

ssize_t z_impl_hwinfo_get_device_id(uint8_t *buffer, size_t length)
{
	static const char id[] = "wallabmc-" CONFIG_BOARD;

	length = MIN(length, sizeof(id) - 1);
	memcpy(buffer, id, length);
	return length;
}
