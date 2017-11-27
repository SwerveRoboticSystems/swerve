%% @file test_ros_scan.m
%  @brief Test MATLAB scan matching by connecting to Gazebo generated scans
%  @author Frederick Wachter - wachterfreddy@gmail.com
%  @author Alex Nhan - NhanAlex320@gmail.com
%  @date Created: 2017-11-26

%% Instructions
% First start roscore in a terminal window then connect MATLAB to running roscore 
% using commands below.
%
% to connect to roscore: rosinit 
%           to shutdown: rosshutdown
%     to start ROS node: N = robotics.ros.Node('laser')

%% Scan Matching Test
laser = rossubscriber('/scan');
figure_handle = figure('Name', 'Robot Position', 'NumberTitle', 'off');

subplot(1 ,2 ,1);
subplot(1, 2 ,2); 

scan_angles = linspace(-2.3562, 2.3562, 810);
transform = [0, 0, 0];

scan = receive(laser, 100);
referenceScan = lidarScan(scan.Ranges, scan_angles);

while (true)

    scan = receive(laser, 100);
    currentScan = lidarScan(scan.Ranges, scan_angles);
    
    transform = transform + matchScans(currentScan, referenceScan);
    
    subplot(1, 2, 1);
    plot(transform(1), transform(2), '.', 'linewidth', 2); axis([-20, 20, -20, 20]);
    title('Robot Position'); axis square;
    xlabel('X Position'); ylabel('Y Position');
    
    subplot(1, 2, 2);
    plot(referenceScan.Cartesian(:,1), referenceScan.Cartesian(:,2), 'k.'); hold on;
    plot(currentScan.Cartesian(:,1), currentScan.Cartesian(:,2), 'r.'); hold off;
    title('Previous and Current Scan Centered at Robot Position'); axis square;
    xlabel('X Position'); ylabel('Y Position');
    legend('Reference Scan', 'Current Scan');
    axis([-20, 20, -20, 20]);
    
    drawnow;
    
    referenceScan = currentScan;
    
end


