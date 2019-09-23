module buzzer (
	start_buzzer;
	clk;
	out_buzzer;
)

input start_buzzer;
input clk;
output out_buzzer;

reg [15:0] cont;
reg working;

always @(clk) begin
	if (working == 1) begin
		cont =  cont + 1; 
	end
end

always @(clk) begin
	if(start_buzzer) begin
		out_buzzer <= 0;
		cont = 0;
		working = 1;
	end
	if(cont >= 5000) begin
		out_buzzer <= 1;
		working = 0;
	end
end