{

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

}
Uses Graph,Crt;
 
const MaxShar=10;
type shar = object
  { переменные }
  x,y:integer; { текущие координаты шара }
  r:word;      { радиус }
  color:byte;  { цвет шара }
  dx,dy:shortint; { скорость. задается значениями
                    перемещения на каждом шаге (в точках) }
  hits:set of byte; { множество шаров с которыми данный шар уже
  столкнулся и с которыми не надо обсчитывать столкновение еще раз }
  { методы }
  constructor initShar(x0,y0:integer; r0:word; color0:byte; dx0,dy0:shortint);
  procedure Move; { двигаем }
  procedure Show; { показываем }
  procedure Hide; { прячем }
  procedure CheckBorder; { проверяем на выход за границы экрана }
  procedure CheckHit(k:byte); { проверяем на столкновение с другим шаром }
  procedure revertXDirection; { поменять Х/Y-составляющую скорости }
  procedure revertYDirection; { на противоположную }
  procedure TurnAfterHit(k:byte); { вычислить новые значения 
               скорости двух шаров после удара. Первый шар - шар 
               данного объекта, второй - с индексом k в массиве }
  function Value:real; { вычислить объем шара. Нужно для вычисления
       скорости. Вообще-то там масса нужна, но учитывая, что плотность
       все-равно сократиться при делении, используем объем }
  {procedure PrintState;} { отладочные печати }
  end;
var bgColor,i:byte;
    x,y,dx,dy,ErrCode:integer;
    r:word;
    shars: array[1..MaxShar] of shar; { массив шаров }
    sh:shar;
    f:text; { файл для отладочных печатей }
Procedure shar.Move;
  begin
  x:=x+dx;
  y:=y+dy;
  end;
Procedure shar.Show;
  begin
  setColor(color);
  circle(x, y, r);
  {PutPixel(x,y,color);} { уберите комментарий чтобы увидеть траекторию }
  end;
Procedure shar.Hide;
  begin
  setColor(bgColor);
  circle(x, y, r);
  end;
procedure shar.revertXDirection;
  begin
  dx:=-dx;
  x:=x+dx;
  end;
procedure shar.revertYDirection;
  begin
  dy:=-dy;
  y:=y+dy;
  end;
Constructor shar.initShar(x0, y0 :integer; r0 :word; color0 :byte; dx0, dy0 :shortint);
  begin
  x:=x0;
  y:=y0;
  r:=r0;
  color:=color0;
  dx:=dx0;
  dy:=dy0;
  hits:=[];
  end;
procedure shar.CheckBorder;
  begin
  if (r+x>=GetMaxX-1) or (x-r<=1) then revertXDirection;
  if (y+r>=GetMaxY-1) or (y-r<=1) then revertYDirection
  end;
{procedure shar.PrintState;
  begin
  writeln(f,'x=',x:3,' y=',y:3,' r=',r:3,' dx=',dx:3,' dy=',dy:3);
  end;}
procedure shar.TurnAfterHit(k:byte);
{ формулы для движения шаров взяты здесь:
  [url]http://ferro.phys.msu.ru/prak/PDF/01-mechanics/07.pdf[/url] }
var m1, m2 :real;
    vx10,vy10,vx20,vy20:integer;
  begin
  m1 := Value;            { массы }
  m2 := shars[k].Value;
  vx10 := dx;             { начальные значения скоростей }
  vy10 := dy;
  vx20 := shars[k].dx;
  vy20 := shars[k].dy;
  { скорость первого шара после удара }
  dx := round((2*m2*vx20 + (m1-m2)*vx10)/(m1+m2));
  dy := round((2*m2*vy20 + (m1-m2)*vy10)/(m1+m2));
  { скорость второго шара после удара }
  shars[k].dx := round((2*m1*vx10 + (m2-m1)*vx20)/(m1+m2));
  shars[k].dy := round((2*m1*vy10 + (m2-m1)*vy20)/(m1+m2));
  end;
function shar.Value:real;
  begin { возвращает объем шара }
  Value:=4*Pi*r*r*r/3;
  end;
procedure shar.CheckHit(k:byte);
var i1:byte;
    dist:longint;
  begin
  for i1:=1 to MaxShar do if ((i1<>k) and not(k in hits)) then
    begin
    shars[i1].hits:=shars[i1].hits+[k];
    dist:=round(sqrt(sqr(1.0*x-shars[i1].x)+sqr(1.0*y-shars[i1].y)));
    if (dist<r+shars[i1].r) then
      begin
      TurnAfterHit(i1);
 
      CheckBorder;
      Move;
      shars[i1].CheckBorder;
      shars[i1].Move;
 
      { скорость задается значениеми dx и dy - шагами движения. Таким
      образом она дискретна. Момент столкновения определяется по
      расстоянию между шарами. Но запросто может случиться, что шары
      на каком-то шаге пересекутся и в этом случае необходимо их
      развести в разные стороны перед тем как высчитывать расстояние на
      следуещем шаге, иначе они могут пребывать в состоянии постоянного
      столкновения }
      dist:=round(sqrt(sqr(1.0*x-shars[i1].x)+sqr(1.0*y-shars[i1].y)));
      while (dist<r+shars[i1].r) do
        begin
        CheckBorder;
        Move;
        shars[i1].CheckBorder;
        shars[i1].Move;
        dist:=round(sqrt(sqr(1.0*x-shars[i1].x)+sqr(1.0*y-shars[i1].y)));
        end;
      end;
    end;
  end;
 
function initializeGraph:integer;
var grDriver : Integer;
      grMode : Integer;
  begin
  grDriver:=Detect;
  InitGraph(grDriver, grMode, '');
  initializeGraph:=GraphResult;
  end;
 
begin
ErrCode:=initializeGraph;
if ErrCode <> grOk then
   WriteLn('Ошибка инициализации графики:', GraphErrorMsg(ErrCode))
else
  begin
  assign(f,'log.txt');
  rewrite(f);
  bgColor:=0;
  rectangle(1,1,GetMaxX-1,GetMaxY-1);
 
  {shars[1].initShar(100,100,50,3,6,-3);
  shars[2].initShar(100,200,40,4,5,3);
  shars[3].initShar(200,200,20,5,-7,-4);
  shars[4].initShar(400,300,25,2,-9,-1);
  shars[5].initShar(500,200,35,14,-5,-8);
  if (MaxShar>5) then}
 
  { инициализация шаров случайным образом }
  for i:=1 to MaxShar do
    begin
    r:=20+random(10);
    shars[i].initShar(1+r+random(GetMaxX-2*r),
      1+r+random(GetMaxY-2*r),r,1+random(GetMaxColor-1),
      random(15)-7,random(12)-6);
    end;
  { обсчитываем движение пока не нажата какая-либо клавиша }
  repeat
    { показываем все шары }
    for i:=1 to MaxShar do
      shars[i].Show;
    { временная задержка - установите свое значение для вашего компьютера }
    Delay(580);
    { убираем с экрана все шары }
    for i:=1 to MaxShar do
      shars[i].Hide;
    { просчитываем следующий шаг }
    for i:=1 to MaxShar do
      begin
      shars[i].Move;
      shars[i].CheckBorder;
      shars[i].CheckHit(i);
      end;
    for i:=1 to MaxShar do
      shars[i].hits:=[];
  until keyPressed;
  CloseGraph;
  close(f);
  end
end
