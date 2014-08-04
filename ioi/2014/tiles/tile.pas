unit tile;

interface

type
	tileType = array[0..21844, 0..5] of longint;

procedure placeTile(n, x, y: longint; var tile: tileType);

implementation

procedure placeTile(n, x, y: longint; var tile: tileType);
begin
end;

end.
