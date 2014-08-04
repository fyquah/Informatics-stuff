unit square;

interface

const
	SIZE = 1000;

type
	materialType = array[0..SIZE-1, 0..SIZE-1] of longint;

function findMaxSquare(material: materialType; materialSize: longint): longint;

implementation

function findMaxSquare(material: materialType; materialSize: longint): longint;
begin
	findMaxSquare := -1;
end;

end.
