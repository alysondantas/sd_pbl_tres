module buzzer (
	start_buzzer,
	clk,
	out_buzzer
);

input start_buzzer;
input clk;
output out_buzzer;

reg out_temp;
reg [15:0] cont;
reg working;

always @(clk) begin
	if (working == 1) begin
		cont =  cont + 1; 
	end
	if (working == 0) begin 
		cont = 0;
	end
end

always @(clk) begin
	if(start_buzzer) begin
		out_temp = 0;
		working = 1;
	end
	if(cont >= 5000) begin
		out_temp = 1;
		working = 0;
	end
end

assign out_buzzer = out_temp;

endmodule