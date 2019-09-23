	component cpu is
		port (
			clk_clk           : in  std_logic                     := 'X'; -- clk
			pio_export        : in  std_logic                     := 'X'; -- export
			pio_lcd_export    : out std_logic_vector(10 downto 0);        -- export
			rs232_RXD         : in  std_logic                     := 'X'; -- RXD
			rs232_TXD         : out std_logic;                            -- TXD
			vga_rgb           : out std_logic_vector(2 downto 0);         -- rgb
			vga_hsync         : out std_logic;                            -- hsync
			vga_vsync         : out std_logic;                            -- vsync
			vga_leds          : out std_logic_vector(7 downto 0);         -- leds
			pio_buzzer_export : out std_logic                             -- export
		);
	end component cpu;

	u0 : component cpu
		port map (
			clk_clk           => CONNECTED_TO_clk_clk,           --        clk.clk
			pio_export        => CONNECTED_TO_pio_export,        --        pio.export
			pio_lcd_export    => CONNECTED_TO_pio_lcd_export,    --    pio_lcd.export
			rs232_RXD         => CONNECTED_TO_rs232_RXD,         --      rs232.RXD
			rs232_TXD         => CONNECTED_TO_rs232_TXD,         --           .TXD
			vga_rgb           => CONNECTED_TO_vga_rgb,           --        vga.rgb
			vga_hsync         => CONNECTED_TO_vga_hsync,         --           .hsync
			vga_vsync         => CONNECTED_TO_vga_vsync,         --           .vsync
			vga_leds          => CONNECTED_TO_vga_leds,          --           .leds
			pio_buzzer_export => CONNECTED_TO_pio_buzzer_export  -- pio_buzzer.export
		);

