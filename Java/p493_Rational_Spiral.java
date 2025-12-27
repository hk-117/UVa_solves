package Solving;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.Collections;
import java.util.TreeMap;
import java.util.Set;
import java.util.TreeSet;
import java.util.Scanner;

class Main {
  private static List<String> fractions = new ArrayList<>();
  private static Set<Long> uniques = new TreeSet<>();
  private static Point[] directions = {
      new Point(0, 1),
      new Point(1, 0),
      new Point(0, -1),
      new Point(-1, 0)
  };
  private static Point position = new Point(0, 0);
  private static DIR direction = DIR.UP;
  private static int stepCount = 1;
  private static final Map<String, DIR> nextDir;
  static {
    Map<String, DIR> map = new TreeMap<>();
    map.put("UP", DIR.RIGHT);
    map.put("RIGHT", DIR.DOWN);
    map.put("DOWN", DIR.LEFT);
    map.put("LEFT", DIR.UP);
    nextDir = Collections.unmodifiableMap(map);
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    while (sc.hasNextInt()) {
      int n = sc.nextInt();
      if (fractions.size() < n + 5) {
        generateSpiral(n + 5);
      }
      System.out.println(fractions.get(n));
    }
    sc.close();
  }

  public static void generateSpiral(int upTo) {
    int stepsApplied = 0;
    while (!(stepsApplied == 2 && fractions.size() >= upTo)) {

      if (stepsApplied == 2) {
        stepsApplied = 0;
        stepCount++;
      }

      for (int i = 1; i <= stepCount; i++) {
        position = position.add(directions[direction.ordinal()]);
        if (position.x != 0) {
          double fraction = (double) position.y / position.x;
          if (fraction == -0.0 || fraction == 0.0) {
            fraction = 0.0;
          }
          long frcLong = (long) (fraction * 1000000000L);
          if (!uniques.contains(frcLong)) {
            uniques.add(frcLong);
            if (fraction < 0) {
              fractions.add(String.format("-%d / %d", Math.abs(position.y), Math.abs(position.x)));
            } else {
              fractions.add(String.format("%d / %d", Math.abs(position.y), Math.abs(position.x)));
            }
          }
        }
      }
      direction = nextDir.get(direction.name());
      stepsApplied++;
    }
    stepCount++;
  }
}

enum DIR {
  UP, RIGHT, DOWN, LEFT
}

class Point {
  int x, y;

  Point(int x, int y) {
    this.x = x;
    this.y = y;
  }

  public Point add(Point other) {
    return new Point(this.x + other.x, this.y + other.y);
  }
}
