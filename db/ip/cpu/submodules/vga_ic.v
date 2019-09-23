module vga_ic(
	data_a,
	data_b,
	clock_en,
   clock,
   disp_RGB,
   hsync,
   vsync,
	leds
);
input [31:0] data_a;
input [31:0] data_b;
input  clock;
input clock_en;
output [2:0]disp_RGB;
output  hsync;
output  vsync;
output [7:0]leds;

reg [9:0] hcount;
reg [9:0] vcount;
reg [2:0] data;
reg [9:0] pad_y_1_begin = 10'd34;
reg [9:0] pad_y_2_begin = 10'd34;
reg [9:0] bola_x_begin = 10'd455;
reg [9:0] bola_y_begin = 10'd266;


reg   flag;
wire  hcount_ov;
wire  vcount_ov;
wire  dat_act;
wire  hsync;
wire   vsync;
reg  vga_clk;


parameter hsync_end   = 10'd95,
   hdat_begin  = 10'd143,
   hdat_end  = 10'd783,
   hpixel_end  = 10'd799,
   vsync_end  = 10'd1,
   vdat_begin  = 10'd34,
   vdat_end  = 10'd514,
   vline_end  = 10'd524;
	
always @(posedge clock)
begin
 vga_clk = ~vga_clk;
end

always @(posedge vga_clk)
begin
 if (hcount_ov)
  hcount <= 10'd0;
 else
  hcount <= hcount + 10'd1;
end
assign hcount_ov = (hcount == hpixel_end);


always @(posedge vga_clk)
begin
 if (hcount_ov)
 begin
  if (vcount_ov)
   vcount <= 10'd0;
  else
   vcount <= vcount + 10'd1;
 end
end
assign  vcount_ov = (vcount == vline_end);

assign dat_act =    ((hcount >= hdat_begin) && (hcount < hdat_end))
     && ((vcount >= vdat_begin) && (vcount < vdat_end));
assign hsync = (hcount > hsync_end);
assign vsync = (vcount > vsync_end);
assign disp_RGB = (dat_act) ?  data : 3'h00;
assign leds = data_a[7:0];

always @(posedge vga_clk)
begin
	if(clock_en) begin
	pad_y_1_begin <= data_a[9:0];
	pad_y_2_begin <= data_a[25:16];
	bola_x_begin <= data_b[25:16];
	bola_y_begin <= data_b[9:0];
	end

	data <=3'h00;
	if(hcount >= bola_x_begin && hcount <= (bola_x_begin + 10'd16))
	begin
		if(vcount >= bola_y_begin && vcount <= (bola_y_begin+10'd16))
		begin
			data <= 3'h07;
		end
	end 
	if(hcount >= 143 && hcount <= 175)
	begin
		if(vcount >= pad_y_1_begin && vcount <= (pad_y_1_begin +10'd96))
		begin
			data <= 3'h07;
		end
	end
	if(hcount >= 751 && hcount <= 783)
	begin
		if(vcount >= pad_y_2_begin && vcount <= (pad_y_2_begin +10'd96))
		begin
			data <= 3'h07;
		end
	end
end
	
	

endmodule

