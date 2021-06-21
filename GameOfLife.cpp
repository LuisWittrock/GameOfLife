/*
 * Regeln:
 * Tote Zelle(0):
 * -Hat sie 3 nachbarn lebt(1) sie in der nächsten Gen.
 * -Hat sie mehr oder weniger bleibt sie tot(0).
 * 
 * Lebende Zelle(1):
 * -weniger als 2 lebende nachbarn resultiert im tot in der nächsten Gen.
 * -2 oder 3 nachbarn bleibt am leben.
 * -4 oder mehr lebende nachbarn und die zelle stirbt in der nächsten Gen.
 */

#include <iostream>

#include <chrono>
#include <thread> 


using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

int main(){
	
	int x = 10, y = 10, i, j, c, b,g;
	int field[y][x] =
	
	{{ 0,0,0,0,0,0,0,0,0,0},
	 { 0,0,0,0,0,0,0,0,0,0},
	 { 0,0,0,1,1,0,0,0,0,0},
	 { 0,0,0,1,0,0,0,0,0,0},
	 { 0,0,0,0,0,0,1,0,0,0},
	 { 0,0,0,0,0,1,1,0,0,0},
	 { 0,0,0,0,0,0,0,0,0,0},
	 { 0,1,1,1,0,0,0,0,0,0},
	 { 0,0,0,0,0,0,0,0,0,0},
	 { 0,0,0,0,0,0,0,0,0,0}};
	 
	int updateField[y][x];
	
	cout << "Anzahl Generationen: ";
	cin >> g;
	
	cout << "start";
	for(b = 0;b<=g; b++){
		cout << "main loop: "<<b<<"\n";
		for(y = 0; y < 10; y++)
		{
			
			for(x = 0; x < 10; x++)
			{
			
			c = 0;
			
			if(y == 0 || y == 9 || x == 0 || x == 9){
				
				
				
			}
			else{
			
				/*v v v lebende zelle v v v*/
				if(field[y][x] == 1){
					
					if(field[y-1][x-1] == 1){
						c++;
					}
					if(field[y-1][x] == 1){
						c++;
					}
					if(field[y-1][x+1] == 1){
						c++;
					}
					if(field[y][x-1] == 1){
						c++;
					}
					if(field[y+1][x-1] == 1){
						c++;
					}
					if(field[y+1][x] == 1){
						c++;
					}
					if(field[y+1][x+1] == 1){
						c++;
					}
					if(field[y][x+1] == 1){
						c++;
					}
					/*regeln v v v*/
					if(c < 2 or c > 3){
						updateField[y][x] = 0;
					}
					else
					{
						updateField[y][x] = 1;
					}
					
					
					
					
				}
				/*^ ^ ^ lebende zelle ^ ^ ^*/
				/*v v v tote zelle v v v*/
				
				else if(field[y][x] == 0){
					
					if(field[y-1][x-1] == 1){
						c++;
					}
					if(field[y-1][x] == 1){
						c++;
					}
					if(field[y-1][x+1] == 1){
						c++;
					}
					if(field[y][x-1] == 1){
						c++;
					}
					if(field[y+1][x-1] == 1){
						c++;
					}
					if(field[y+1][x] == 1){
						c++;
					}
					if(field[y+1][x+1] == 1){
						c++;
					}
					if(field[y][x+1] == 1){
						c++;
					}
					/*regeln v v v*/
					if(c == 3)
					{
						updateField[y][x] = 1; 
					}
					else
					{
						updateField[y][x] = 0;
					}
				}
				
			}
			
		}
	}
	cout << "\n";
	for(i = 1; i < 9; i++){
		for(j = 1; j < 9; j++){
			field[i][j] = updateField[i][j];
			
			
		}
	}
		
		for(i = 0;i < x; i++){
			for(j = 0; j < y; j++ )
			{
				cout << field[i][j];
				
			}
		cout << "\n";
		}
		sleep_for(nanoseconds(500000000));
	}
	
	
	
}
