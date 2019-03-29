<!DOCTYPE html>
<html lang="en">
<head>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
  <!-- Global site tag (gtag.js) - Google Analytics -->
<script async src="https://www.googletagmanager.com/gtag/js?id=UA-117442547-1"></script>
<script>
  window.dataLayer = window.dataLayer || [];
  function gtag(){dataLayer.push(arguments);}
  gtag('js', new Date());

  gtag('config', 'UA-117442547-1');
</script>

</head>
<body>

  <nav class="navbar navbar-default">
    <div class="container-fluid">
      <div class="navbar-header">
        <a class="navbar-brand"><img src="images/ChiefsLogoLarge.jpg" alt="ChiefsLogoLarge" width="75" height="75" </a>
      </div>
              <h1>Lakewood Chiefs Hockey</h1>
    </div>
  </nav>
  <nav class="navbar navbar-default">
    <div class="container-fluid">
      <!-- Brand and toggle get grouped for better mobile display -->
      <div class="navbar-header">
        <button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target="#bs-example-navbar-collapse-1" aria-expanded="false">
          <span class="sr-only">Toggle navigation</span>
          <span class="icon-bar"></span>
          <span class="icon-bar"></span>
          <span class="icon-bar"></span>
        </button>
</div>

      <!-- Collect the nav links, forms, and other content for toggling -->
      <div class="collapse navbar-collapse" id="bs-example-navbar-collapse-1">
        <ul class="nav navbar-nav">
          <li><a href="index.html">Home <span class="sr-only">(current)</span></a></li>
          <li ><a href="team.php">Team </a></li>
          <li ><a href="scores.php">Scores</a></li>
          <li class="active"><a href="standings.php">Standings</a></li>
          <li><a href="schedule.php">Schedule</a></li>
          <li><a href="stats.php">Stats</a></li>
        </ul>
      </div><!-- /.navbar-collapse -->
    </div><!-- /.container-fluid -->
  </nav>

  <div class="container-fluid">
    <div class="row">
      <div class="col-md-4">
      </div>
      <div class="col-md-4">
        <img src="images/under_construction.png" class="img-responsive pull-left" alt="UnderConstruction">
      </div>
      <div class="col-md-4"></div>
    </div>
  </div>
<div class="container-fluid">
  <div class="row">
    <div class="col-md-6">

      <?php
    include 'chiefs_config.php';
    include 'chiefs_opendb.php';

    mysqli_close($conn);
    ?>
    </div>
    <div class="col-md-6">

      <?php
    include 'chiefs_config.php';
    include 'chiefs_opendb.php';

    mysqli_close($conn);
    ?>
    </div>
  </div>
</div>
<hr>
<div class="container-fluid">
	<div class="row">
		<div class="col-md-4">
        <p>Copyright, Contact Us, Etc.</p>
		</div>
    <div class="col-md-4">
        <p>Team Standings</p>
      </div>
      <div class="col-md-4">
    <a href="index.html"><img src="images/FBLogo.png" class="img-responsive pull-left" alt="Facebook" width="50" height="50"></a>
     <a href="index.html"><img src="images/TwLogo.jpg" class="img-responsive pull-left" alt="Twitter" width="50" height="50"></a>
      <a href="index.html"><img src="images/InstLogo.jpg" class="img-responsive pull-left" alt="Instagram" width="50" height="50"></a>
        </div>
	</div>
</div>
</body>
</html>
