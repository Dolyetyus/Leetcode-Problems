class Solution(object):
    def robotSim(self, commands, obstacles):
        obstacle_set = set(map(tuple, obstacles))
        position = [0, 0]
        direction = 0
        # Directions: 0 = north, 1 = east, 2 = south, 3 = west
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        ret = 0

        for command in commands:
            if command == -1:
                direction = (direction + 1) % 4
            elif command == -2:
                direction = (direction - 1) % 4
            else:
                for _ in range(command):
                    next_position = [position[0]+directions[direction][0], position[1]+directions[direction][1]]
                    if tuple(next_position) not in obstacle_set:
                        position = next_position
                        ret = max(ret, position[0]**2 + position[1]**2)
                    else:
                        break

        return ret

    ''' Alternate solution
    def robotSim(self, commands, obstacles):
        obstacle_set = set(map(tuple, obstacles))
        position = [0, 0]
        direction = 0
        # Directions: 0 = north, 1 = east, 2 = south, 3 = west
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        ret = 0

        for command in commands:
            if command == -1:
                direction = (direction + 1) % 4
            elif command == -2:
                direction = (direction - 1) % 4
            else:
                new_x = position[0]+directions[direction][0]*command
                new_y = position[1]+directions[direction][1]*command
                for obs in obstacles:
                    obs_relative_x = True if position[0]<obs[0] else False
                    obs_relative_y = True if position[1]<obs[1] else False

                    if position[1] == obs[1]:
                        if obs_relative_x and (position[0] < obs[0] < new_x):
                            new_x = obs[0]-1
                        if (not obs_relative_x) and (position[0] > obs[0] > new_x):
                            new_x = obs[0]+1

                    if position[0] == obs[0]:
                        if obs_relative_y and (position[1] < obs[1] < new_y):
                            new_y = obs[1]-1
                        if (not obs_relative_y) and (position[1] > obs[1] > new_y):
                            new_y = obs[1]+1

                position = [new_x, new_y]
                print(position)
                ret = max(ret, (position[0]**2) + (position[1]**2))

        return ret'''
