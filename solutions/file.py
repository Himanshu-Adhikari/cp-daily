import os
import shutil

base_path = os.getcwd()

for item in os.listdir(base_path):
    full_path = os.path.join(base_path, item)

    # Check if it's a directory and matches YYYY-MM-DD format
    if os.path.isdir(full_path) and len(item) >= 10 and item[4] == '-' and item[7] == '-':
        prefix = item[:7]  # YYYY-MM
        
        prefix_path = os.path.join(base_path, prefix)

        # Create YYYY-MM folder if it doesn't exist
        if not os.path.exists(prefix_path):
            os.mkdir(prefix_path)

        # Move folder inside YYYY-MM
        shutil.move(full_path, os.path.join(prefix_path, item))

print("Done restructuring.")