import sys
import csv
import matplotlib.pyplot as plt
from matplotlib.patches import Patch

# sz_2pow: size in 2 power of
#
summary_csv_name = "output/test/summary/summary.csv"
filled_summary_csv_name = "output/test/summary/filled_summary.csv"
output_dirname = "output/test/summary"

def get_plot_dict(title: str):
  x = list(range(10, 31, 1))

  return {
    "title": title,
    "color": {
      "array_of_sorted_arrays": "#DD4444",
      "btree":                  "#7EBDA4",
      "hashtable":              "#AA8844",
      "skiplist":               "#4589BC",
      "treap":                  "#CAAACD"
    },
    "handle": [
      Patch(color='#DD4444', label="Array of sorted arrays"),
      Patch(color='#7EBDA4', label="B-Tree"),
      Patch(color='#AA8844', label="Hash Table"),
      Patch(color='#4589BC', label="Skip List"),
      Patch(color='#CAAACD', label="Treap")
    ],
    "x": x,
    "xy": {
      "array_of_sorted_arrays": 
        { sz_2pow: 0 for sz_2pow in x },
      "btree": 
        { sz_2pow: 0 for sz_2pow in x },
      "hashtable":
        { sz_2pow: 0 for sz_2pow in x },
      "skiplist":
        { sz_2pow: 0 for sz_2pow in x },
      "treap":
        { sz_2pow: 0 for sz_2pow in x }
    }
  }

plot_dicts = {
  "insert": get_plot_dict("Insert Time"),
  "search": get_plot_dict("Search Time")
}

with open(summary_csv_name, "r", newline = "") as f:
  csv_rows = csv.DictReader(f,
    delimiter = ",", 
    lineterminator = "\n",
    quoting = csv.QUOTE_MINIMAL
  )

  # build `plot_dicts`
  #
  BLANK = -1
  for row in csv_rows:
    stname = row["structure_name"]
    opname = row["operation_name"]
    size = int(row["size_in_2_power_of"])
    time = row["time_in_millisecond"]
    time = BLANK if not time else int(time)

    plot_dicts[opname]["xy"][stname][size] = time

  # fill blank with predictive value
  #
  for plot_dict in plot_dicts.values():
    for xy in plot_dict["xy"].values():
      for x, y in xy.items():
        if y == BLANK:
          xy[x] = int(xy[x - 1] / xy[x - 2]) * xy[x - 1]
        elif y == 0:
          xy[x] = 1

  # drawing plots
  #
  for plot_name, plot_dict in plot_dicts.items():
    fig = plt.figure()
    ax = fig.add_subplot(111)

    fig.set_size_inches(8, 6)
    plt.xticks(plot_dict["x"])
    plt.grid(which = 'both', alpha = 0.4)

    # putting data on the plot
    #
    for stname, xy in plot_dict["xy"].items():
      # ref: https://stackoverflow.com/a/52244724
      #
      for i, v in enumerate(xy.values()):
        ax.text(i + 10, v, 
          f"{v}", 
          ha = "center", 
          fontsize = 4, 
          fontdict = {
            "color": plot_dict["color"][stname]
          }
        )

      plt.plot(
        xy.keys(),
        xy.values(),
        color = plot_dict["color"][stname],
        alpha = 0.8,
        linewidth = 2
      )

      plt.scatter(
        x = xy.keys(), 
        y = xy.values(), 
        c = plot_dict["color"][stname], 
        s = 4
      )
    
    # putting tags on the plot
    #
    plt.title(plot_dict["title"])
    plt.xlabel("Size in 2 power of")
    plt.ylabel('Millisecond')
    plt.legend(handles = plot_dict["handle"])

    plt.yscale('log')

    savepath = f"{output_dirname}/{plot_name}"
    plt.savefig(savepath, dpi = 400)
    print(f"output plot: {savepath}")
