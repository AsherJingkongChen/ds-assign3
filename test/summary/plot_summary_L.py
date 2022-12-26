import sys
import csv
import matplotlib.pyplot as plt
from matplotlib.patches import Patch

BLANK = -1

# sz_2pow: size in 2 power of
#
summary_csv_name = "output/test/summary/summary_L.csv"
filled_summary_csv_name = "output/test/summary/filled_summary_L.csv"
output_dirname = "output/test/summary"

def get_plot_dict(title: str):
  x = list(range(20, 30, 1))

  return {
    "title": title,
    "color": {
      "array_of_sorted_arrays": "#DD4444",
      "L_array_of_sorted_arrays": "#EA77EE",
      # "btree":                  "#7EBDA4",
      # "hashtable":              "#AA8844",
      # "skiplist":               "#4589BC",
      # "treap":                  "#CA8ACD"
    },
    "handle": [
      Patch(color='#DD4444', label="Array of sorted arrays"),
      Patch(color='#EA77EE', label="Lee's Array of sorted arrays"),
      # Patch(color='#7EBDA4', label="B-Tree"),
      # Patch(color='#AA8844', label="Hash Table"),
      # Patch(color='#4589BC', label="Skip List"),
      # Patch(color='#CA8ACD', label="Treap")
    ],
    "x": x,
    "xy": {
      "array_of_sorted_arrays": 
        { sz_2pow: 0 for sz_2pow in x },
      "L_array_of_sorted_arrays": 
        { sz_2pow: 0 for sz_2pow in x },
      # "btree": 
      #   { sz_2pow: 0 for sz_2pow in x },
      # "hashtable":
      #   { sz_2pow: 0 for sz_2pow in x },
      # "skiplist":
      #   { sz_2pow: 0 for sz_2pow in x },
      # "treap":
      #   { sz_2pow: 0 for sz_2pow in x }
    }
  }

plot_dicts = {
  "insert": get_plot_dict("Insert Time"),
  # "search": get_plot_dict("Search Time")
}

with open(summary_csv_name, "r", newline = "") as f:
  csv_rows = csv.DictReader(f,
    delimiter = ",", 
    lineterminator = "\n",
    quoting = csv.QUOTE_MINIMAL
  )

  # build `plot_dicts`
  #
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
    for stname, xy in plot_dict["xy"].items():
      for x, y in xy.items():
        if y == BLANK:
          xy[x] = int(xy[x - 1] ** 2 / xy[x - 2])
        elif y == 0:
          xy[x] = 1

  # write predictive data to 
  # <output_dirname>/prediction_insert.csv,
  # <output_dirname>/prediction_search.csv
  #
  for opname in plot_dicts.keys():
    with open(
        f"{output_dirname}/prediction_{opname}_L.csv", 
        "w", newline = "") as f:

      csv_out = csv.DictWriter(f,
        delimiter = ",",
        lineterminator = "\n",
        quoting = csv.QUOTE_MINIMAL,
        fieldnames = 
          ["size_in_2_power_of"] + 
          list(get_plot_dict("")["color"].keys())
      )

      rows = []

      for x in get_plot_dict("")["x"]:
        row = {
          stname: xy[x] 
          for stname, xy in plot_dicts[opname]["xy"].items()
        }
        row["size_in_2_power_of"] = x
        rows.append(row)

      csv_out.writeheader()
      csv_out.writerows(rows)
    
  # drawing plots
  #
  for plot_name, plot_dict in plot_dicts.items():
    fig = plt.figure()
    ax = fig.add_subplot(111)

    # timeout line
    #
    plt.plot(
      get_plot_dict("")["x"],
      [3600000] * len(get_plot_dict("")["x"]),
      "-.",
      color = "#A33333",
      linewidth = 1
    )

    fig.set_size_inches(7, 4)
    plt.xticks(plot_dict["x"])
    plt.grid(which = 'both', alpha = 0.3)

    # putting data on the plot
    #
    for stname, xy in plot_dict["xy"].items():
      # ref: https://stackoverflow.com/a/52244724
      #
      for i, v in enumerate(xy.values()):
        ax.text(i + min(get_plot_dict("")["x"]), v, 
          f"{v}", 
          ha = "center", 
          fontsize = 6, 
          fontdict = {
            "color": plot_dict["color"][stname]
          }
        )

      plt.plot(
        xy.keys(),
        xy.values(),
        color = plot_dict["color"][stname],
        alpha = 0.7,
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
    plt.legend(
      handles = plot_dict["handle"],
      fontsize = 8
    )

    plt.yscale('symlog')

    savepath = f"{output_dirname}/{plot_name}_L_large.png"
    plt.savefig(savepath, dpi = 350)
    print(f"output plot: {savepath}")

    savepath = f"{output_dirname}/{plot_name}_L_small.png"
    plt.savefig(savepath, dpi = 150)
    print(f"output plot: {savepath}")
