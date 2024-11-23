#pragma once

#include <ISmmPlugin.h>
#include <serversideclient.h>
#include "../public/iaudioplayer.h"
#include "opus/opus.h"

#ifdef _WIN32
#define ROOTBIN "/bin/win64/"
#define GAMEBIN "/csgo/bin/win64/"
#else
#define ROOTBIN "/bin/linuxsteamrt64/"
#define GAMEBIN "/csgo/bin/linuxsteamrt64/"
#endif

void Message(const char *msg, ...);
void Panic(const char *msg, ...);

extern OpusEncoder *encoder;
extern std::string g_TempDir;

class AudioPlayer : public ISmmPlugin,
                    public IMetamodListener
{
public:
  bool Load(PluginId id, ISmmAPI *ismm, char *error, size_t maxlen, bool late);
  bool Unload(char *error, size_t maxlen);
  void *OnMetamodQuery(const char *iface, int *ret);
  // static void ProcessAudio();

public:
  void Hook_StartupServer(const GameSessionConfiguration_t &config, ISource2WorldSession *, const char *);
  int Hook_LoadEventsFromFile(const char *filename, bool bSearchAll);

public:
  const char *GetAuthor();
  const char *GetName();
  const char *GetDescription();
  const char *GetURL();
  const char *GetLicense();
  const char *GetVersion();
  const char *GetDate();
  const char *GetLogTag();
};