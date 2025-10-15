# Slides

Le slides sono scritte usando [Marp](https://marp.app), che permette di crearle a partire da testo Markdown.

Per compilarle, usate [l'estensione per VSCode](https://marketplace.visualstudio.com/items?itemName=marp-team.marp-vscode)

Da terminale si può andare con il [CLI](https://github.com/marp-team/marp-cli) (richiede NPM). Si può lanciare con

```bash
npx @marp-team/marp-cli@latest 0.model.md --pdf --allow-local-files
```

> Assicurarsi di avere installato Chrome, perché Firefox non va. In caso si avesse installato solamente Chromium, esportate questa variabile (o equivalente per il vostro sistema operativo)

> ```bash
> export CHROME_PATH="/Applications/Chromium.app/Contents/MacOS/Chromium"
> ```

# Argomenti

Gli argomenti che affronteremo sono:

1. introduction, I/O & data structures
2. sorting & time complexity
3. greedy
4. graphs, DFS & BFS
5. recorsion & dynamic programming
6. shortest path & spanning
7. Tree algorithms
