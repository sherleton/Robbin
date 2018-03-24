      google.charts.load('current', {'packages':['gantt']});
    google.charts.setOnLoadCallback(drawChart);

    function drawChart() {

      var data = new google.visualization.DataTable();
      data.addColumn('string', 'Task ID');
      data.addColumn('string', 'Task Name');
      data.addColumn('string', 'Resource');
      data.addColumn('date', 'Start Date');
      data.addColumn('date', 'End Date');
      data.addColumn('number', 'Duration');
      data.addColumn('number', 'Percent Complete');
      data.addColumn('string', 'Dependencies');

      data.addRows([
        ['a', 'Get dustbin and other materials ready', 'a',
         new Date(2017, 1, 27), new Date(2017, 2, 2), null, 100, null],
        ['b', 'Create base', 'b',
         new Date(2017, 2, 2), new Date(2017, 2, 6), null, 100, null],
        ['c', 'Add ultrasonic sensors & do rotation', 'c',
         new Date(2017, 2, 6), new Date(2017, 2, 9), null, 100, null],
        ['d', 'Create arms', 'd',
         new Date(2017, 2, 9), new Date(2017, 2, 14), null, 100, null],
        ['sensor', 'Move arms based on sensors', 'Hardware',
         new Date(2017, 2, 14), new Date(2017, 2, 20), null, 100, null],
        ['software', 'Connect motor & relay, write their code', 'Software',
         new Date(2017, 2, 20), new Date(2017, 2, 23), null, 100, null],
        ['arms', 'Attach ultrasonic sensor at top and GSM module', 'Hardwar',
         new Date(2017, 2, 23), new Date(2017, 2, 27), null, 100, null],
        ['mix', 'Connect dumbbell plate & finish piston', 'Ware',
         new Date(2017, 2, 27), new Date(2017, 2, 29), null, 100, null],
        ['piston', 'Run tests', 'Hardwa',
         new Date(2017, 2, 29), new Date(2017, 2, 31), null, 100, null],
        ['app', 'Combine everything', 'Softwar',
         new Date(2017, 2, 31), new Date(2017, 3, 3), null, 100, null],
        ['testing', 'Troubleshooting', 'Testing',
         new Date(2017, 3, 3), new Date(2017, 3, 8), null, 100, null],
        ['testin', 'Buffer time for possible delays', 'Testin',
         new Date(2017, 3, 8), new Date(2017, 3, 15), null, 100, null]
      ]);

      var options = {
        height: 400,
        gantt: {
          trackHeight: 30
        }
      };

      var chart = new google.visualization.Gantt(document.getElementById('chart_div'));

      chart.draw(data, options);
    }
