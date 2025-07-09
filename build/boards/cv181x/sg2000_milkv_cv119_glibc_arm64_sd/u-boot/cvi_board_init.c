static void set_rtc_register_for_power(void)
{
	printf("set_rtc_register_for_power\n");

	// Reset Key
	mmio_write_32(0x050260D0, 0x7);
}

int cvi_board_init(void)
{
	// Camera0
	PINMUX_CONFIG(IIC3_SCL, IIC3_SCL);
	PINMUX_CONFIG(IIC3_SDA, IIC3_SDA);
	PINMUX_CONFIG(CAM_MCLK0, CAM_MCLK0); // Sensor0 MCLK
	PINMUX_CONFIG(CAM_RST0, XGPIOA_2);   // Sensor0 RESET

	// USB
	PINMUX_CONFIG(USB_VBUS_EN, XGPIOB_5);

	set_rtc_register_for_power();

	return 0;
}
