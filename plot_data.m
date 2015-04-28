% data from the file
data = dlmread("data.csv", ",");

% Show the number of data values;
size(data)

date = data(:,1);
temp = data(:,3);

% Plot date against time
plot(date, temp);

% Comment
Randon stuff