,>	store value in cell 0
,	store value in cell 1
------------------------------------------------ convert cell 1 to 0
<	move to cell 0
------------------------------------------------ convert cell 0 to 0
multiply
[
	>	move to cell 1
	[>+>+<<-]    store cell 2 to cell 3
	>	move to cell 2
	[<+>-]	add cell 1 to cell 2
	<<-	reset loop
]

>>>	move to cell 3
++++++++++++++++++++++++++++++++++++++++++++++++ convert cell 3 to ascii
.	print cell 3
