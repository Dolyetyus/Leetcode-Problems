class Solution(object):
    def removeSubfolders(self, folder):
        folder.sort()
        i = 0

        while i < len(folder):
            subfolder = folder[i]
            seek = i+1

            while seek < len(folder) and folder[seek].startswith(subfolder + '/'):
                seek += 1
            
            folder = folder[:i + 1] + folder[seek:]
            i+=1

        return folder
