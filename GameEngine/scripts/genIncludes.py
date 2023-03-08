import os
import shutil

def init_folder(folder):
    if os.path.exists(folder):
        shutil.rmtree(folder)
    os.makedirs(folder)

def main():
    folder = "Includes/header/"
    init_folder(folder)
    for root, dirs, files in os.walk("src/Classes"):
        path = root.split(os.sep)
        for file in files:
            if file.endswith(".hpp"):
                res = folder + os.path.join("/".join(root.split("/")[2:]))
                os.makedirs(res, exist_ok=True)
                shutil.copy(os.path.join(root, file), res)

if __name__ == "__main__":
    main()
