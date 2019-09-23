	cpu u0 (
		.clk_clk           (<connected-to-clk_clk>),           //        clk.clk
		.pio_export        (<connected-to-pio_export>),        //        pio.export
		.pio_lcd_export    (<connected-to-pio_lcd_export>),    //    pio_lcd.export
		.rs232_RXD         (<connected-to-rs232_RXD>),         //      rs232.RXD
		.rs232_TXD         (<connected-to-rs232_TXD>),         //           .TXD
		.vga_rgb           (<connected-to-vga_rgb>),           //        vga.rgb
		.vga_hsync         (<connected-to-vga_hsync>),         //           .hsync
		.vga_vsync         (<connected-to-vga_vsync>),         //           .vsync
		.vga_leds          (<connected-to-vga_leds>),          //           .leds
		.pio_buzzer_export (<connected-to-pio_buzzer_export>)  // pio_buzzer.export
	);

