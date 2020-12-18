// https://leetcode.com/problems/word-ladder-ii/
import { runTests } from './util';

class Node {
    parent: (Node | null);
    word: string;

    constructor(word: string, parent: (Node | null) = null) {
      this.parent = parent;
      this.word = word;
    }

    isNeighbor(other_word: string): boolean {
      let distance = 0;
      for (let i = 0; i < this.word.length; ++i) {
        if (this.word[i] != other_word[i]) {
          distance += 1;
          if (distance > 1)
            return false;
        }
      }
      return distance === 1;
    }

    path(): string[] {
      let output: string[] = [];
      let node: (Node | null) = this;
      while (node != null) {
        output.unshift(node.word);
        node = node.parent;
      }
      return output;
    }
}

const findLadders = (
  beginWord: string, endWord: string, wordList: string[]) => {
    if (!wordList.includes(endWord)) {
      return [];
    }

    // create 2 trees, to search from both ends
    const frontiers: Node[][] = [[new Node(beginWord)], [new Node(endWord)]];
    let pathFound = false;
    const paths: string[][] = [];
    const visited: Set<string> = new Set();

    while (!pathFound && frontiers.every(arr => arr.length)) {
      const frontier = frontiers.shift() || [];
      const queue: Node[] = [];
      frontiers.push(queue);
      const otherQueue = frontiers[0];

      // check if we've completed a path
      frontier.forEach(next => {
        otherQueue.forEach(otherWord => {
          if (next.word == otherWord.word) {
            // we have found a match, no longer add to the queue,
            // but do finish processing existing nodes
            pathFound = true;
            // convert both trees to arrays and join them
            const otherPath = otherWord.path();
            otherPath.pop();
            let path = next.path().concat(otherPath.reverse());
            if (path[0] != beginWord)
              path.reverse();
            paths.push(path);
          }
        });

        // add words to the next frontier
        wordList.forEach(word => {
          if (!pathFound && next.isNeighbor(word) && !visited.has(word)) {
            queue.push(new Node(word, next));
            visited.add(next.word);
          }
        });
      });
    }
    return paths;
}

runTests('126-word-ladder-ii.json', findLadders);
