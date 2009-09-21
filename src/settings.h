#ifndef _SETTINGS_H
#define _SETTINGS_H
#define PREFIXLEN 16

#define SETTINGS_VER 1

typedef struct settings_struct {
  char prefix[PREFIXLEN];
  /* -- STATIC -- */
//  char hash[33];
  char hash[49];
  char packname[65];
  char shellhash[65];
  char owners[513];
  char hubs[513];
  char owneremail[385];
  char salt1[33];
  char salt2[17];
  char dcc_prefix[17];
  char features[17];
  /* -- DYNAMIC -- */
  char bots[1025];
  char uid[17];
  char autouname[17];        /* should we just auto update any changed in uname output? */
  char autocron[17];         /* should the bot auto crontab itself? */
  char watcher[17];          /* spawn a watcher pid to block ptrace? */
  char uname[113];
  char username[49];       /* shell username */
  char datadir[1025];
  char homedir[1025];        /* homedir */
  char binpath[1025];        /* path to binary, ie: ~/ */
  char binname[113];        /* binary name, ie: .sshrc */
  char portmin[17];       /* for hubs, the reserved port range for incoming connections */
  char portmax[17];       /* for hubs, the reserved port range for incoming connections */
  /* -- PADDING -- */
  char padding[9];
} settings_t;

#define SALT1 {s1_1[0],s1_1[1],s1_5[0],s1_5[1],s1_8[0],s1_8[1],s1_4[0],s1_9[1],s1_2[0],s1_13[0],s1_6[0],s1_6[1],s1_7[0],s1_7[1],s1_3[0],s1_13[1],s1_16[1],s1_4[1],s1_15[0],s1_10[1],s1_14[0],s1_14[1],s1_12[0],s1_12[1],s1_2[1],s1_3[1],s1_11[0],s1_11[1],s1_10[0],s1_15[1],s1_16[0],s1_9[0],'\0'}
#define SALT2 {s2_5[0],s2_5[1],s2_2[0],s2_2[1],s2_8[1],s2_4[0],s2_7[1],s2_4[1],s2_1[0],s2_6[0],s2_1[1],s2_6[1],s2_3[0],s2_3[1],s2_8[0],s2_7[0],'\0'}
#define _x_1 settings.salt1
#define _x_2 settings.salt2
#define INIT_SALTS s2_6[1]=_x_2[11];s1_10[0]=_x_1[28];s1_5[1]=_x_1[3];s2_4[0]=_x_2[5];s1_2[1]=_x_1[24];s2_2[1]=_x_2[3];s1_13[1]=_x_1[15];s1_7[0]=_x_1[12];s1_4[1]=_x_1[17];s2_8[0]=_x_2[14];s1_6[0]=_x_1[10];s1_15[0]=_x_1[18];s1_7[1]=_x_1[13];s1_8[0]=_x_1[4];s1_16[0]=_x_1[30];s1_1[0]=_x_1[0];s1_9[1]=_x_1[7];s1_3[1]=_x_1[25];s2_3[1]=_x_2[13];s2_4[1]=_x_2[7];s1_3[0]=_x_1[14];s1_12[0]=_x_1[22];s1_8[1]=_x_1[5];s1_1[1]=_x_1[1];s2_1[0]=_x_2[8];s1_10[1]=_x_1[19];s1_14[0]=_x_1[20];s1_11[0]=_x_1[26];s2_7[1]=_x_2[6];s2_1[1]=_x_2[10];s1_9[0]=_x_1[31];s2_2[0]=_x_2[2];s1_15[1]=_x_1[29];s2_5[1]=_x_2[1];s2_5[0]=_x_2[0];s1_16[1]=_x_1[16];s2_6[0]=_x_2[9];s1_13[0]=_x_1[9];s1_2[0]=_x_1[8];s1_5[0]=_x_1[2];s2_8[1]=_x_2[4];s1_6[1]=_x_1[11];s2_3[0]=_x_2[12];s2_7[0]=_x_2[15];s1_12[1]=_x_1[23];s1_4[0]=_x_1[6];s1_14[1]=_x_1[21];s1_11[1]=_x_1[27];
extern char s1_3[3],s1_2[3],s1_1[3],s2_7[3],s1_9[3],s1_13[3],s1_14[3],s2_2[3],s1_10[3],s2_4[3],s1_4[3],s2_3[3],s2_1[3],s2_6[3],s1_7[3],s1_12[3],s2_5[3],s1_5[3],s1_6[3],s1_11[3],s2_8[3],s1_8[3],s1_16[3],s1_15[3];

#define SIZE_PACK sizeof(settings.hash) + sizeof(settings.packname) + sizeof(settings.shellhash) + \
sizeof(settings.owners) + sizeof(settings.hubs) + sizeof(settings.owneremail) + \
sizeof(settings.salt1) + sizeof(settings.salt2) + sizeof(settings.dcc_prefix) + sizeof(settings.features)

#define SIZE_CONF sizeof(settings.bots) + sizeof(settings.uid) + sizeof(settings.autouname) + \
sizeof(settings.autocron) + sizeof(settings.watcher) + sizeof(settings.uname) + \
sizeof(settings.username) + sizeof(settings.homedir) + sizeof(settings.binpath) + sizeof(settings.binname) + \
sizeof(settings.portmin) + sizeof(settings.portmin) + sizeof(settings.datadir)

#define SIZE_PAD sizeof(settings.padding)

#define SIZE_SETTINGS sizeof(settings_t)

extern settings_t       settings;

#endif /* !_SETTINGS_H */
