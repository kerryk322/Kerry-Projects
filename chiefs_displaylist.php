<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="utf-8">
  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <!-- jQuery (necessary for Bootstrap's JavaScript plugins) -->
  <script src="https://ajax.googleapis.com/ajax/libs/jquery/1.12.4/jquery.min.js"></script>
  <!-- Include all compiled plugins (below), or include individual files as needed -->
  <script src="js/bootstrap.min.js"></script>
  <script src="js/scripts.js"></script>

  <title>Team Roster</title>

  <link href="css/bootstrap.min.css" rel="stylesheet">
  <link href="css/style.css" rel="stylesheet">

</head>
<body>

  <div class="container-fluid">
  <div class="row">
  <div class="col-md-12">
    <ul class="nav nav-tabs">
      <li>
        <a href="index.html">Home</a>
      </li>
      <li>
        <a href="team.html">Page 1</a>
      </li>
      <li>
        <a href="#">Page 2</a>
      </li>
      <li>
        <a href="#">Page 3</a>
      </li>
      <li  class="active">
        <a href="chiefs_displaylist.php">Display List</a>
      </li>
    </ul>
    <div class="jumbotron">
      <h2>
        Page 1
      </h2>
      <p>
        Lorem ipsum dolor sit amet, <strong>consectetur adipiscing elit</strong>. Aliquam eget sapien sapien. Curabitur in metus urna. In hac habitasse platea dictumst. Phasellus eu sem sapien, sed vestibulum velit. Nam purus nibh, lacinia non faucibus et, pharetra in dolor. Sed iaculis posuere diam ut cursus. <em>Morbi commodo sodales nisi id sodales. Proin consectetur, nisi id commodo imperdiet, metus nunc consequat lectus, id bibendum diam velit et dui.</em> Proin massa magna, vulputate nec bibendum nec, posuere nec lacus. <small>Aliquam mi erat, aliquam vel luctus eu, pharetra quis elit. Nulla euismod ultrices massa, et feugiat ipsum consequat eu.</small>
      </p>
      <p>
        <a class="btn btn-primary btn-large" href="#">Learn more</a>
      </p>
    </div>
    <div class="row">
      <div class="col-md-4">
        <?php
      include 'mod3_config.php';
      include 'mod3_opendb.php';

      $sql= "SELECT FirstName, LastName, EmailAddress FROM contact LIMIT 10";
      $result = mysqli_query($conn, $sql);

      if (mysqli_num_rows($result) > 0) {
          // output data of each row
          while($row = mysqli_fetch_assoc($result)) {
              echo "FirstName: " . $row["FirstName"]. "<br>";
              echo "LastName: " . $row["LastName"]. "<br>";
              echo "EmailAddress: " . $row["EmailAddress"]. "<br><hr>";
          }
      } else {
          echo "0 results";
      }

      mysqli_close($conn);

      ?>
      </div>
      <div class="col-md-4">
        <p>
          Lorem ipsum dolor sit amet, <strong>consectetur adipiscing elit</strong>. Aliquam eget sapien sapien. Curabitur in metus urna. In hac habitasse platea dictumst. Phasellus eu sem sapien, sed vestibulum velit. Nam purus nibh, lacinia non faucibus et, pharetra in dolor. Sed iaculis posuere diam ut cursus. <em>Morbi commodo sodales nisi id sodales. Proin consectetur, nisi id commodo imperdiet, metus nunc consequat lectus, id bibendum diam velit et dui.</em> Proin massa magna, vulputate nec bibendum nec, posuere nec lacus. <small>Aliquam mi erat, aliquam vel luctus eu, pharetra quis elit. Nulla euismod ultrices massa, et feugiat ipsum consequat eu.</small>
        </p>
      </div>
      <div class="col-md-4">
        <p>
          Lorem ipsum dolor sit amet, <strong>consectetur adipiscing elit</strong>. Aliquam eget sapien sapien. Curabitur in metus urna. In hac habitasse platea dictumst. Phasellus eu sem sapien, sed vestibulum velit. Nam purus nibh, lacinia non faucibus et, pharetra in dolor. Sed iaculis posuere diam ut cursus. <em>Morbi commodo sodales nisi id sodales. Proin consectetur, nisi id commodo imperdiet, metus nunc consequat lectus, id bibendum diam velit et dui.</em> Proin massa magna, vulputate nec bibendum nec, posuere nec lacus. <small>Aliquam mi erat, aliquam vel luctus eu, pharetra quis elit. Nulla euismod ultrices massa, et feugiat ipsum consequat eu.</small>
        </p>
      </div>
    </div>
  </div>
  </div>
  </div>


</div>
</body>
</html>
