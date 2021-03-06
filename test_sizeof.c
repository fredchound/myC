#include <stdio.h>

int main (void)
{

	union u {
		struct {
			char reason_code;
			} deauth;
		struct {
			short auth_alg;
			short auth_transaction;
			short status_code;
			char variable[1];
			} auth;
		};
	union u *pu;

/*
	union u2 {
		struct {
			char reason_code;
			} deauth;
		struct {
			short auth_alg;
			short auth_transaction;
			short status_code;
			char variable[3];
			}  auth;
		};
	union u2 *pu2;	
*/

	struct ieee80211_mgmt {
		unsigned short frame_control;		
		unsigned short duration;
		char da[6];
		char sa[6];
		char bssid[6];
		unsigned short seq_ctrl;
		union u su;
	}; //end of struct ieee80211_mgmt

	struct ieee80211_mgmt *mgmt; 
	
	printf("size of char is %d \n", sizeof(char));
	printf("size of short is %d \n", sizeof(short));
	printf("size of the union is %d \n", sizeof(*pu));
	printf("size of the struct is %d \n", sizeof(*mgmt) );
	

	printf("size of pointer is %d \n", sizeof(void*));
	return 0;

} //end of main
