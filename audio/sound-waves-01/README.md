Play some simple sound waves in C. Sourced from https://zserge.com/posts/etude-in-c/

This example needs SoX to play on Windows: http://sox.sourceforge.net/. The download is an installer. After install is complete, copy the sox file and rename it to 'play', which is a special sox keyword, and referenced in the article.

The latest release of sox, 14.4.2, did not work for me. Consistently saw the error  FAIL sox: Sorry, there is no default audio device configured.

I tried with 14.4.1 instead on the recommendation of some GitHub issues / SO posts. This worked in a cmd terminal:

.\white-noise.exe | play -c1 -b8 -eunsigned -traw -r8k -

The training - is significant, it instructs play to accept the re-directed input from .\white-noise.exe.

I compiled these examples with the VS2019 Developer Command Prompt. Inside the prompt:

```
cl white-noise.c
cl oscillators.c
cl sequencers.c
```

sox seems to need a full buffer before it will play a sample. In the sequencers program, entering "8e5 8b4 8d5 8e5 8d5 8b4 8a4 8b4" causes playback to stop mid-stream, but entering more notes will cause the remaining un-played notes to play.