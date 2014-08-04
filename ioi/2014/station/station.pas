unit station;

interface

type
	LodgeType = array[0..499999] of longint;

function findMinDays(n, k: longint; lodge: LodgeType): longint;

implementation

function findMinDays(n, k: longint; lodge: LodgeType): longint;
begin
	findMinDays := -2;
end;

end.
