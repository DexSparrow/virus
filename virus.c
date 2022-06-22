#include <stdio.h>
#include <stdlib.h>

int lelen(char*z){
	int i = 0;
	char*zz = z;
	for (i ;*zz != '\0'; ++zz){
		i++;

	}
	return i;
}

char* reverse(char*a){
	char*aa = a;
	int n = lelen(a);
	char*res = (void*)malloc((n+1)*sizeof(char));
	char*sres = res;
	aa += n -1;
	for (int i = 0; i < n; ++i){
		*res = *aa;
		res++,aa--;
	}
	return sres;
}


char* fuses(char*a,char*b){
	char*aa = a;
	char*bb = b;
	int la = lelen(a);
	int lb = lelen(b);
	char*res = (void*)malloc((la + lb + 1)*sizeof(char));
	char*sres = res;
	for (int i = 0; i < la; ++i){
		*res = *aa;
		res++,aa++;
	}
	for (int i = 0; i < lb; ++i){
		*res = *bb;
		res++,bb++;
	}
	return sres;
}


char* Stringy(int n){
	int res,modu,ros;
	int count = 1;
	res = n;
	while(res > 10){
		res = res / 10;
		count++;
	}
	count++;
	char*resu = (void*)malloc((count+1)*sizeof(char));
	char*sresu = resu;
	res = n;
	
	while(res > 10){
		ros = res/10;
		modu = res%10;
		*resu = (char)(modu + 48);
		res = ros;
		resu++;
	}
	*resu = (char)(res+48);
	resu = sresu;
	resu = reverse(resu);
	return resu;	
}

void main() {
	int limi = 10000;
	FILE*file;
	for (int i = 0; i <= limi; ++i){
		char*res = fuses("index",Stringy(i));
		char*final = fuses(res,".html");
		file = fopen(final,"w");
		fclose(file);
	}
}






