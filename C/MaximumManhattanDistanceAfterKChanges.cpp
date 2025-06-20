#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

int maxDistance(char* s, int k) {
        int n = strlen(s);
        int N = 0;
        int S = 0; 
        int E = 0; 
        int W = 0; 
        int dist = 0;

        for (int i=0; i<n; i++){
            char c=s[i];
            switch(c){
                case 'N':N++; break;
                case 'S':S++; break;
                case 'E':E++; break;
                case 'W':W++; break;
            }
            const int d = abs(N-S) + abs(E-W) + 2*k;
            dist = MAX(dist, MIN(d, i+1));
        }
        return dist;
}
