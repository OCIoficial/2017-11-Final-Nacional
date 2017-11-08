import java.util.*;
public class mmunos {
	static final int N = 64;
	static boolean[][] input = new boolean[N][N];
	static int[][] dir = { {0,1},{0,-1},{1,0},{-1,0} };
	public static void main(String[] args) throws Exception {
		Scanner seer = new Scanner(System.in);
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				int k = seer.nextInt();
				if(k == 1) input[i][j] = true;
			}
		}
		int zones = zones(clone_input());
		int[] horz_scan_stats = new int[N];
		for(int i = 0; i < N; i++){
			horz_scan_stats[i] = horz_scan(i);
		}
		int[] vert_scan_stats = new int[N];
		for(int j = 0; j < N; j++){
			vert_scan_stats[j] = vert_scan(j);
		}
		String h_str = compress(horz_scan_stats);
		String v_str = compress(vert_scan_stats);
		if(zones == 1){// 0, 1, 2, 3, 4, 6, 7
			int h_scan_something = 0, v_scan_something = 0;
			for(int i = 0; i < N; i++){
				if(horz_scan_stats[i] > 0) h_scan_something++;
				if(vert_scan_stats[i] > 0) v_scan_something++;
			}
			if(h_scan_something * 3 < v_scan_something){ //0 if bounding box of the drawing is thin enough
				System.out.println(0);
			}
			else if(v_scan_something * 3 < h_scan_something){//1 if yes
				System.out.println(1);
			}
			else if(v_str.equals("010")){// 2, 3, 7
				if(h_str.contains("3") || h_str.contains("4")){// 7
					System.out.println(7);
				}
				else if(h_str.equals("0210")){// heur2 
					System.out.println(2);
				}
				else if(h_str.equals("0120")){// heur3
					System.out.println(3);
				}
				else if(h_str.equals("01210")){
					//find the bottommost of the first 2's (a)
					//and the topmost of the second 2's (b)
					//and compare them
					int a = 0, b = 0;
					for(int i = 0; i < N; i++){
						if(horz_scan_stats[i] == 2){
							a = i-1; break;
						}
					}
					for(int i = a+1; i < N; i++){
						if(horz_scan_stats[i] == 1){
							b = i; break;
						}
					}
					int a_width = 0, b_width = 0;
					for(int i = 0; i < N; i++){
						if(input[a][i]) a_width++;	
					}
					for(int i = 0; i < N; i++){
						if(input[b][i]) b_width++;
					}
					if(a_width > b_width){
						System.out.println(3);
					}
					else{
						System.out.println(2);
					}
				}
				else{// I don't know what this could be
					System.out.println("Tal vez la magia no es para ti.");
				}
			}
			else{// 4, 6
				if(v_str.contains("3")){//4
					System.out.println(4);
				}
				else{//6
					System.out.println(6);
				}
			}
		}
		if(zones == 2){// 5
			System.out.println(5);
		}
		if(zones == 3){// 8, 9
			if(h_str.contains("4")){//heur8
				System.out.println(8);
			}
			else{//weirdest heuristic
				int h1 = 0, v1 = 0;
				for(int i = 0; i < N; i++){
					if(horz_scan_stats[i] == 1){
						for(int j = 0; j < N; j++){
							if(input[i][j]) h1++;
						}
					}
				}
				for(int j = 0; j < N; j++){
					if(vert_scan_stats[j] == 1){
						for(int i = 0; i < N; i++){
							if(input[i][j]) v1++;
						}
					}
				}
				if(h1 > v1){
					System.out.println(9);
				}
				else{
					System.out.println(8);
				}
			}
		}
	}
	static String compress(int[] arr){
		StringBuilder sb = new StringBuilder();
		int prev = -1;
		for(int k: arr){
			if(prev != k){
				sb.append(k+"");
				prev = k;
			}
		}
		return sb.toString();
	}
	static int horz_scan(int _i){
		boolean state = false;
		int res = 0;
		int buffer = 0; //for cleaning squiggly diagonal lines, doesn't really help for horizontal or vertical lines
		for(int j = 0; j < N; j++){
			if(!state && input[_i][j]){
				if(buffer < 3){
					buffer++;
				}
				else{
					state = true;
					res++;
				}
			}
			else if(state && !input[_i][j]){
				state = false;
				buffer = 0;
			}
		}
		return res;
	}
	static int vert_scan(int _j){
		boolean state = false;
		int res = 0;
		int buffer = 0;
		for(int i = 0; i < N; i++){
			if(!state && input[i][_j]){
				if(buffer < 3){
					buffer++;
				}
				else{
					state = true;
					res++;
				}
			}
			else if(state && !input[i][_j]){
				state = false;
				buffer = 0;
			}
		}
		if(state) res++;
		return res;
	}
	static int zones(boolean[][] map){
		int res = 0;
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				if(!map[i][j]){
					fill(map, i, j);
					res++;
				}
			}
		}
		return res;
	}
	static boolean fill(boolean[][] map, int a, int b){
		if(map[a][b]) return false;
		else{
			ArrayList<Coor> q = new ArrayList<>();
			map[a][b] = true;
			q.add(new Coor(a,b));
			while(!q.isEmpty()){
				Coor c = q.remove(0);
				for(int[] d: dir){
					int x = c.x+d[0]; int y = c.y+d[1];
					if(x >= 0 && x < N && y >= 0 && y < N && !map[x][y]){
						map[x][y] = true;
						q.add(new Coor(x,y));
					}
				}
			}
			return true;
		}
	}
	static boolean[][] clone_input(){
		boolean[][] res = new boolean[N][N];
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				res[i][j] = input[i][j];
			}
		}
		return res;
	}
	static class Coor{
		int x, y;
		public Coor(int x, int y){
			this.x = x; this.y = y;
		}
	}
}
