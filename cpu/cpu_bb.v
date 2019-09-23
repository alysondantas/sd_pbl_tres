
module cpu (
	clk_clk,
	pio_export,
	pio_lcd_export,
	rs232_RXD,
	rs232_TXD,
	vga_rgb,
	vga_hsync,
	vga_vsync,
	vga_leds,
	pio_buzzer_export);	

	input		clk_clk;
	input		pio_export;
	output	[10:0]	pio_lcd_export;
	input		rs232_RXD;
	output		rs232_TXD;
	output	[2:0]	vga_rgb;
	output		vga_hsync;
	output		vga_vsync;
	output	[7:0]	vga_leds;
	output		pio_buzzer_export;
endmodule
