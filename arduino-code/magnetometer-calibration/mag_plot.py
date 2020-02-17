from matplotlib import pyplot as plt
import numpy as np
import argparse
import pandas as pd

parser = argparse.ArgumentParser()
parser.add_argument("data_file",type=str,help="csv file with magnetometer readings")
args = parser.parse_args()

values = pd.read_csv(args.data_file)
x = values['x']
y = values['y']
print("x-offset",(max(x)+min(x))/2)
print("y-offset",(max(y)+min(y))/2)
fig, ax = plt.subplots()
ax.scatter(values['x'],values['y'],alpha=0.3)
ax.grid(True)
plt.show()