<html><head><META http-equiv="Content-Type" content="text/html; charset=iso-8859-1"><title>Catalina Functional Specifications - Administrative Apps - Administered Objects</title><meta value="Craig McClanahan" name="author"><meta value="craigmcc@apache.org" name="email"></head><body vlink="#525D76" alink="#525D76" link="#525D76" text="#000000" bgcolor="#ffffff"><table cellspacing="4" width="100%" border="0"><!--PAGE HEADER--><tr><td colspan="2"><!--JAKARTA LOGO--><a href="http://jakarta.apache.org/"><img border="0" alt="The Jakarta Project" align="left" src="../../../images/jakarta-logo.gif"></a><!--PROJECT LOGO--><a href="http://jakarta.apache.org/tomcat/"><img border="0" alt="
      Catalina Functional Specifications
    " align="right" src="../../../images/tomcat.gif"></a></td></tr><!--HEADER SEPARATOR--><tr><td colspan="2"><hr size="1" noshade=""></td></tr><tr><!--RIGHT SIDE MAIN BODY--><td align="left" valign="top" width="80%"><table cellspacing="4" width="100%" border="0"><tr><td nowrap="true" valign="top" align="left"><h1>Catalina Functional Specifications</h1><h2>Administrative Apps - Administered Objects</h2></td><td nowrap="true" valign="top" align="right"><img border="0" hspace="0" vspace="0" height="1" width="1" src="../../../images/void.gif"></td></tr></table><table cellpadding="2" cellspacing="0" border="0"><tr><td bgcolor="#525D76"><font face="arial,helvetica.sanserif" color="#ffffff"><a name="Administered%20Objects%20Overview"><strong>Administered Objects Overview</strong></a></font></td></tr><tr><td><blockquote>

<p>This document defines the <em>Administered Objects</em> that represent
the internal architectural components of the Catalina servlet container.
Associated with each is a set of <a href="fs-admin-opers.html">Supported
Operations</a> that can be performed when the administrative application is
"focused" on a particular configurable object.</p>

<p>The following Administered Objects are defined:</p>
<ul>
<li><a href="#Access%20Logger">Access Logger</a></li>
<li><a href="#Connector">Connector</a></li>
<li><a href="#Context">Context</a></li>
<li><a href="#Default%20Context">Default Context</a></li>
<li><a href="#Default%20Deployment%20Descriptor">Default Deployment Descriptor</a></li>
<li><a href="#Engine">Engine</a></li>
<li><a href="#Environment%20Entry">Environment Entry</a></li>
<li><a href="#Host">Host</a></li>
<li><a href="#JDBC%20Resource">JDBC Resource</a></li>
<li><a href="#Loader">Loader</a></li>
<li><a href="#Logger">Logger</a></li>
<li><a href="#Manager">Manager</a></li>
<li><a href="#Realm">Realm</a></li>
<li><a href="#Request%20Filter">Request Filter</a></li>
<li><a href="#Server">Server</a></li>
<li><a href="#Service">Service</a></li>
</ul>

</blockquote></td></tr></table><table cellpadding="2" cellspacing="0" border="0"><tr><td bgcolor="#525D76"><font face="arial,helvetica.sanserif" color="#ffffff"><a name="Access%20Logger"><strong>Access Logger</strong></a></font></td></tr><tr><td><blockquote>

  <p>An <em>Access Logger</em> is an optional <code>Valve</code> that can
  create request access logs in the same formats as those provided by
  web servers.  Such access logs are useful input to hit count and user
  access tracking analysis programs.  An Access Logger can be attached to
  an <em>Engine</em>, a <em>Host</em>, a <em>Context</em>, or a <em>Default
  Context</em>.</p>

  <p>The standard component implementing an <em>Access Logger</em> is
  <code>org.apache.catalina.valves.AccessLogValve</code>.  It supports the
  following configurable properties:</p>
  <ul>
  <li><code>debug</code> - Debugging detail level.  [0]</li>
  <li><code>directory</code> - Absolute or relative (to $CATALINA_HOME) path
      of the directory into which access log files are created.
      [logs].</li>
  <li><code>pattern</code> - Pattern string defining the fields to be
      included in the access log output, or "common" for the standard
      access log pattern.  See
      <code>org.apache.catalina.valves.AccessLogValve</code> for more
      information.  [common]</li>
  <li><code>prefix</code> - Prefix added to the beginning of each log file
      name created by this access logger.</li>
  <li><code>resolveHosts</code> - Should IP addresses be resolved to host
      names in the log?  [false]</li>
  <li><code>suffix</code> - Suffix added to the end of each log file name
      created by this access logger.</li>
  </ul>

</blockquote></td></tr></table><table cellpadding="2" cellspacing="0" border="0"><tr><td bgcolor="#525D76"><font face="arial,helvetica.sanserif" color="#ffffff"><a name="Connector"><strong>Connector</strong></a></font></td></tr><tr><td><blockquote>

  <p>A <em>Connector</em> is the representation of a communications endpoint
  by which requests are received from (and responses returned to) a Tomcat
  client.  The administrative applications shall support those connectors
  that are commonly utilized in Tomcat installations, as described in detail
  below.</p>

  <p>For standalone use, the standard connector supporting the HTTP/1.1
  protocol is <code>org.apache.catalina.connectors.http.HttpConnector</code>.
  It supports the following configurable properties:</p>
  <ul>
  <li><code>acceptCount</code> - The maximum queue length of incoming
      connections that have not yet been accepted.  [10]</li>
  <li><code>address</code> - For servers with more than one IP address, the
      address upon which this connector should listen.  [All Addresses]</li>
  <li><code>bufferSize</code> - Default input buffer size (in bytes) for
      requests created by this Connector.  [2048]</li>
  <li><code>debug</code> - Debugging detail level.  [0]</li>
  <li><code>enableLookups</code> - Should we perform DNS lookups on remote
      IP addresses when <code>request.getRemoteHost()</code> is called?
      [true]</li>
  <li><code>maxProcessors</code> - The maximum number of processor threads
      supported by this connector.  [20]</li>
  <li><code>minProcessors</code> - The minimum number of processor threads
      to be created at container startup.  [5]</li>
  <li><code>port</code> - TCP/IP port number on which this Connector should
      listen for incoming requests. [8080]</li>
  <li><code>proxyName</code> - Host name to be returned when an application
      calls <code>request.getServerName()</code>.  [Value of Host: header]</li>
  <li><code>proxyPort</code> - Port number to be returned when an application
      calls <code>request.getServerPort()</code>.  [Same as <code>port</code>]
      </li>
  </ul>

</blockquote></td></tr></table><table cellpadding="2" cellspacing="0" border="0"><tr><td bgcolor="#525D76"><font face="arial,helvetica.sanserif" color="#ffffff"><a name="Context"><strong>Context</strong></a></font></td></tr><tr><td><blockquote>

  <p>A <em>Context</em> is the representation of an individual web application,
  which is associated with a corresponding <em>Host</em>.  Note that the
  administrable properties of a <em>Context</em> do <strong>not</strong>
  include any settings from inside the web application deployment descriptor
  for that application.</p>

  <p>The standard component implementing a <em>Context</em> is
  <code>org.apache.catalina.core.StandardContext</code>.  It supports the
  following configurable properties:</p>
  <ul>
  <li><code>cookies</code> - Should be use cookies for session identifier
      communication?  [true]</li>
  <li><code>crossContext</code> - Should calls to
      <code>ServletContext.getServletContext()</code> return the actual
      context responsible for the specified path?  [false]</li>
  <li><code>debug</code> - Debugging detail level.  [0]</li>
  <li><code>docBase</code> - The absolute or relative (to the
      <code>appBase</code> of our owning <em>Host</em>) pathname of a
      directory containing an unpacked web application, or of a web
      application archive (WAR) file.</li>
  <li><code>override</code> - Should settings in this <em>Context</em>
      override corresponding settings in the <em>Default Context</em>?
      [false]</li>
  <li><code>path</code> - Context path for this web application, or an empty
      string for the root application of a <em>Host</em>.  [Inferred from
      directory or WAR file name]</li>
  <li><code>reloadable</code> - Should Tomcat monitor classes in the
      <code>/WEB-INF/classes</code> directory for changes, and reload the
      application if they occur?  [false]</li>
  <li><code>useNaming</code> - Should Tomcat provide a JNDI naming context,
      containing preconfigured entries and resources, corresponding to the
      requirements of the Java2 Enterprise Edition specification?  [true]</li>
  <li><code>workDir</code> - Absolute pathname of a scratch directory that is
      provided to this web application.  [Automatically assigned relative to
      $CATALINA_HOME/work]</li>
  </ul>

  <p>Each <em>Context</em> is owned by a parent <em>Host</em>, and is
  associated with:</p>
  <ul>
  <li>An optional <em>Access Logger</em> that logs all requests processed
      by this web application.</li>
  <li>Zero or more <em>Environment Entries</em> representing environment
      entries for the JNDI naming context associated with a web
      application.</li>
  <li>Zero or more <em>JDBC Resources</em> representing database connection
      pools associated with a web application.</li>
  <li>A <em>Loader</em> representing the web application class loader used
      by this web application.</li>
  <li>An optional <em>Logger</em> that logs all internally generated debug,
      information, and error messages (including application messages using
      <code>ServletContext.log()</code>).</li>
  <li>A <em>Manager</em> representing the session manager used by this
      web application.</li>
  <li>An optional <em>Realm</em> used to provide authentication and access
      control information for this web application.</li>
  <li>Zero or more <em>Request Filters</em> used to limit access to this
      web application based on remote host name or IP address.</li>
  </ul>

</blockquote></td></tr></table><table cellpadding="2" cellspacing="0" border="0"><tr><td bgcolor="#525D76"><font face="arial,helvetica.sanserif" color="#ffffff"><a name="Default%20Context"><strong>Default Context</strong></a></font></td></tr><tr><td><blockquote>

  <p>A <em>Default Context</em> represents a subset of the configurable
  properties of a <em>Context</em>, and is used to set defaults for those
  properties when web applications are automatically deployed.  A <em>Default
  Context</em> object can be associated with an <em>Engine</em> or a
  <em>Host</em>.  The following configurable properties are supported:</p>
  <ul>
  <li><code>cookies</code> - Should be use cookies for session identifier
      communication?  [true]</li>
  <li><code>crossContext</code> - Should calls to
      <code>ServletContext.getServletContext()</code> return the actual
      context responsible for the specified path?  [false]</li>
  <li><code>reloadable</code> - Should Tomcat monitor classes in the
      <code>/WEB-INF/classes</code> directory for changes, and reload the
      application if they occur?  [false]</li>
  <li><code>useNaming</code> - Should Tomcat provide a JNDI naming context,
      containing preconfigured entries and resources, corresponding to the
      requirements of the Java2 Enterprise Edition specification?  [true]</li>
  </ul>

  <p>Each <em>Default Context</em> is owned by a parent <em>Engine</em> or
  <em>Host</em>, and is associated with:</p>
  <ul>
  <li>Zero or more <em>Environment Entries</em> representing environment
      entries for the JNDI naming context associated with a web
      application.</li>
  <li>Zero or more <em>JDBC Resources</em> representing database connection
      pools associated with a web application.</li>
  <li>An optional <em>Loader</em> representing default configuration
      properties for the Loader component of deployed web applications.</li>
  <li>An optional <em>Manager</em> representing default configuration
      properties for the Manager component fo deployed web applications.</li>
  </ul>

</blockquote></td></tr></table><table cellpadding="2" cellspacing="0" border="0"><tr><td bgcolor="#525D76"><font face="arial,helvetica.sanserif" color="#ffffff"><a name="Default%20Deployment%20Descriptor"><strong>Default Deployment Descriptor</strong></a></font></td></tr><tr><td><blockquote>

  <p>Default web application characteristics are configured in a special
  deployment descriptor named <code>$CATALINA_HOME/conf/web.xml</code>.  This
  section describes the configurable components that may be stored there.</p>

  <p><strong>FIXME</strong> - Complete the description of default servlets,
  default mappings, default MIME types, and so on.</p>

</blockquote></td></tr></table><table cellpadding="2" cellspacing="0" border="0"><tr><td bgcolor="#525D76"><font face="arial,helvetica.sanserif" color="#ffffff"><a name="Engine"><strong>Engine</strong></a></font></td></tr><tr><td><blockquote>

  <p>An <em>Engine</em> is the representation of the entire Catalina
  servlet container, and processes all requests for all of the associated
  virtual hosts and web applications.</p>

  <p>The standard component implementing an <em>Engine</em> is
  <code>org.apache.catalina.core.StandardEngine</code>.  It supports the
  following configurable properties:</p>
  <ul>
  <li><code>debug</code> - Debugging detail level.  [0]</li>
  <li><code>defaultHost</code> - Name of the <em>Host</em> to which requests
      will be directed if the requested host is unknown.  [localhost]</li>
  <li><code>name</code> - Logical name of this engine. [Tomcat Stand-Alone]
      </li>
  </ul>

  <p>Each <em>Engine</em> is owned by a parent <em>Service</em>, and is
  associated with:</p>
  <ul>
  <li>An optional <em>Access Logger</em> that logs all requests processed
      by the entire container.</li>
  <li>A <em>Default Context</em>, representing default properties of a
      <em>Context</em> for automatically deployed applications for all
      associated <em>Hosts</em> (unless overridden by a subordinate
      component).</li>
  <li>One or more <em>Hosts</em> representing individual virtual hosts
      supported by this container.</li>
  <li>A <em>Logger</em> that logs all internally generated debug, information,
      and error messages (unless overridden by a subordinate component).</li>
  <li>A <em>Realm</em> used to provide authentication and access control
      information for all virtual hosts and web applications (unless
      overridden by a subordinate component).</li>
  <li>Zero or more <em>Request Filters</em> used to limit access to the
      entire container based on remote host name or IP address.</li>
  </ul>

</blockquote></td></tr></table><table cellpadding="2" cellspacing="0" border="0"><tr><td bgcolor="#525D76"><font face="arial,helvetica.sanserif" color="#ffffff"><a name="Environment%20Entry"><strong>Environment Entry</strong></a></font></td></tr><tr><td><blockquote>

  <p>An <em>Environment Entry</em> is the representation of a
  <code>&lt;env-entry&gt;</code> element from a web application deployment
  descriptor.  It will cause the creation of a corresponding entry in the
  JNDI naming context provided to the corresponding <em>Context</em>.  The
  following configurable properties are supported:</p>
  <ul>
  <li><code>description</code> - Description of this environment entry.</li>
  <li><code>name</code> - Environment entry name (relative to the
      <code>java:comp/env</code> context)</li>
  <li><code>type</code> - Environment entry type (must be one of the fully
      qualified Java classes listed in the servlet spec).</li>
  <li><code>value</code> - Environment entry value (must be convertible from
      String to the specified <code>type</code>.</li>
  </ul>

</blockquote></td></tr></table><table cellpadding="2" cellspacing="0" border="0"><tr><td bgcolor="#525D76"><font face="arial,helvetica.sanserif" color="#ffffff"><a name="Host"><strong>Host</strong></a></font></td></tr><tr><td><blockquote>

  <p>A <em>Host</em> is the representation of an individual virtual host,
  which has a unique set of associated web applications.</p>

  <p>The standard component implementing a <em>Host</em> is
  <code>org.apache.catalina.core.StandardHost</code>.  It supports the
  following configurable properties:</p>
  <ul>
  <li><code>aliases</code> - Zero or more DNS names that are also associated
      with this host (for example, a particular host might be named
      <code>www.mycompany.com</code> with an alias <code>company.com</code>).
      </li>
  <li><code>appBase</code> - Absolute or relative (to $CATALINA_HOME) path
      to a directory from which web applications will be automatically
      deployed.</li>
  <li><code>debug</code> - Debugging detail level.  [0]</li>
  <li><code>name</code> - DNS Name of the virtual host represented by this
      object.</li>
  <li><code>unpackWARs</code> - Should web application archive files
      deployed by this virtual host be unpacked first?  [true]</li>
  </ul>

  <p>Each <em>Host</em> is owned by a parent <em>Engine</em>, and is
  associated with:</p>
  <ul>
  <li>An optional <em>Access Logger</em> that logs all requests processed
      by this virtual host.</li>
  <li>One or more <em>Contexts</em> representing the web applications
      operating on this <em>Host</em>.</li>
  <li>A <em>Default Context</em> representing default <em>Context</em>
      properties for web applications that are automatically deployed
      by this <em>Host</em>.</li>
  <li>An optional <em>Logger</em> that logs all internally generated debug,
      information, and error messages (unless overridden by a subordinate
      component).</li>
  <li>A optional <em>Realm</em> used to provide authentication and access
      control information for all web applications associated with this
      virtual host (unless overridden by a subordinate component).</li>
  </ul>

  <p><strong>FIXME</strong> - Should we support configuration of the
  User Web Applications functionality?</p>

</blockquote></td></tr></table><table cellpadding="2" cellspacing="0" border="0"><tr><td bgcolor="#525D76"><font face="arial,helvetica.sanserif" color="#ffffff"><a name="JDBC%20Resource"><strong>JDBC Resource</strong></a></font></td></tr><tr><td><blockquote>

  <p>A <em>JDBC Resources</em> represents a database connection pool (i.e.
  an implementation of <code>javax.sql.DataSource</code> that will be
  configured and made available in the JNDI naming context associated with
  a web application.</p>

  <p><strong>FIXME</strong> - properties of this administered object</p>

</blockquote></td></tr></table><table cellpadding="2" cellspacing="0" border="0"><tr><td bgcolor="#525D76"><font face="arial,helvetica.sanserif" color="#ffffff"><a name="Loader"><strong>Loader</strong></a></font></td></tr><tr><td><blockquote>

  <p>A <em>Loader</em> represents a web application class loader that will
  be utilized to provide class loading services for a particular
  <em>Context</em>.</p>

  <p>The standard component implementing a <em>Loader</em> is
  <code>org.apache.catalina.loader.StandardLoader</code>.  It supports
  the following configurable properties:</p>
  <ul>
  <li><code>checkInterval</code> - Number of seconds between checks for
      modified classes, if automatic reloading is enabled.  [15]</li>
  <li><code>debug</code> - Debugging detail level.  [0]</li>
  <li><code>reloadable</code> - Should this class loader check for modified
      classes and initiate automatic reloads?  [Set automatically from the
      <code>reloadable</code> property of the corresponding <em>Context</em>]
      </li>
  </ul>

  <p>Each <em>Loader</em> is owned by a parent <em>Context</em>.</p>

</blockquote></td></tr></table><table cellpadding="2" cellspacing="0" border="0"><tr><td bgcolor="#525D76"><font face="arial,helvetica.sanserif" color="#ffffff"><a name="Logger"><strong>Logger</strong></a></font></td></tr><tr><td><blockquote>

  <p>A <em>Logger</em> represents an object that stores debugging traces,
  error messages, and other information on some permanent (or transient)
  media.  Several standard implementations are provided (with
  <code>FileLogger</code> being the default).</p>

  <p><code>org.apache.catalina.logger.FileLogger</code> creates disk files
  in a specified directory, with the filenames being a combination of the
  specified prefix, the current date, and the specified suffix.  The logger
  will switch log files automatically on the first logged message after
  midnight, without requiring a restart of the entire container.  The
  following configurable properties are supported:</p>
  <ul>
  <li><code>debug</code> - Debugging detail level.  [0]</li>
  <li><code>directory</code> - Absolute or relative (to $CATALINA_HOME) path
      of the directory in which log files are created.  [logs]</li>
  <li><code>prefix</code> - String added to the beginning of generated log
      file names.  [catalina]</li>
  <li><code>suffix</code> - String added to the end of generated log file
      names.  [.log]</li>
  <li><code>timestamp</code> - Should log messages be date/time stamped?
      [true]</li>
  <li><code>verbosity</code> - Minimum verbosity level for messages to be
      actually written to this logger.  Note that messages that are logged
      with no verbosity level at all are logged unconditionally.  [0]</li>
  </ul>

  <p><code>org.apache.catalina.logger.SystemErrLogger</code> logs all messages
  to the system error stream of the process running the container.  The
  following configurable properties are supported:</p>
  <ul>
  <li><code>debug</code> - Debugging detail level.  [0]</li>
  <li><code>verbosity</code> - Minimum verbosity level for messages to be
      actually written to this logger.  Note that messages that are logged
      with no verbosity level at all are logged unconditionally.  [0]</li>
  </ul>

  <p><code>org.apache.catalina.logger.SystemOutLogger</code> logs all messages
  to the system output stream of the process running the container.  The
  following configurable properties are supported:</p>
  <ul>
  <li><code>debug</code> - Debugging detail level.  [0]</li>
  <li><code>verbosity</code> - Minimum verbosity level for messages to be
      actually written to this logger.  Note that messages that are logged
      with no verbosity level at all are logged unconditionally.  [0]</li>
  </ul>

  <p>Each <em>Logger</em> is owned by a parent <em>Engine</em>,
  <em>Host</em>, or <em>Context</em>.</p>

</blockquote></td></tr></table><table cellpadding="2" cellspacing="0" border="0"><tr><td bgcolor="#525D76"><font face="arial,helvetica.sanserif" color="#ffffff"><a name="Manager"><strong>Manager</strong></a></font></td></tr><tr><td><blockquote>

  <p>A <em>Manager</em> represents a session manager that will be associated
  with a particular web application.  <strong>FIXME</strong> - Add support
  for advanced session managers and their associated Stores.</p>

  <p>The standard component implementing a <em>Manager</em> is
  <code>org.apache.catalina.session.StandardManager</code>.  It supports
  the following configurable properties:</p>
  <ul>
  <li><code>checkInterval</code> - Number of seconds between checks for
      expired sessions.  [60]</li>
  <li><code>debug</code> - Debugging detail level.  [0]</li>
  <li><code>entropy</code> - String initialization parameter used to increase
      the entropy (initial randomness) of the random number generator used to
      create session identifiers.  [Inferred from engine, host, and context]
      </li>
  <li><code>maxActiveSessions</code> - The maximum number of active sessions
      that are allowed, or -1 for no limit.  [-1]</li>
  </ul>

  <p>Each <em>Manager</em> is owned by a parent <em>Context</em>.</p>

</blockquote></td></tr></table><table cellpadding="2" cellspacing="0" border="0"><tr><td bgcolor="#525D76"><font face="arial,helvetica.sanserif" color="#ffffff"><a name="Realm"><strong>Realm</strong></a></font></td></tr><tr><td><blockquote>

  <p>A <em>Realm</em> represents a "database" of information about authorized
  users, their passwords, and the security roles assigned to them.  This will
  be used by the container in the implementation of container-managed security
  in accordance with the Servlet Specification.  Several alternative
  implementations are supported.</p>

  <p><code>org.apache.catalina.realm.MemoryRealm</code> initializes its user
  information from a simple XML file at startup time.  If changes are made
  to the information in this file, the corresponding web applications using
  it must be restarted for the changes to take effect.  It supports the
  following configurable properties:</p>
  <ul>
  <li><code>debug</code> - Debugging detail level.  [0]</li>
  <li><code>pathname</code> - Absolute or relative (to $CATALINA_HOME) path to
      the XML file containing our user information.  [conf/tomcat-users.xml]
      </li>
  </ul>

  <p><code>org.apache.catalina.realm.JDBCRealm</code> uses a relational
  database (accessed via JDBC APIs) to contain the user information.  Changes
  in the contents of this database take effect immediately; however, the roles
  assigned to a particular user are calculated only when the user initially
  logs on (and not per request).  The following configurable properties
  are supported:</p>
  <ul>
  <li><code>connectionName</code> - Database username to use when establishing
      a JDBC connection.</li>
  <li><code>connectionPassword</code> - Database password to use when
      establishing a JDBC connection.</li>
  <li><code>connectionURL</code> - Connection URL to use when establishing
      a JDBC connection.</li>
  <li><code>debug</code> - Debugging detail level.  [0]</li>
  <li><code>digest</code> - Name of the <code>MessageDigest</code> algorithm
      used to encode passwords in the database, or a zero-length string for
      no encoding.  [Zero-length String]</li>
  <li><code>driverName</code> - Fully qualified Java class name of the JDBC
      driver to be utilized.</li>
  <li><code>roleNameCol</code> - Name of the column, in the User Roles table,
      which contains the role name.</li>
  <li><code>userCredCol</code> - Name of the column, in the Users table,
      which contains the password (encrypted or unencrypted).</li>
  <li><code>userNameCol</code> - Name of the column, in both the Users and
      User Roles tables, that contains the username.</li>
  <li><code>userRoleTable</code> - Name of the User Roles table, which contains
      one row per security role assigned to a particular user.  This table must
      contain the columns specified by the <code>userNameCol</code> and
      <code>roleNameCol</code> properties.</li>
  <li><code>userTable</code> - Name of the Users table, which contains one row
      per authorized user.  This table must contain the columns specified by
      the <code>userNameCol</code> and <code>userCredCol</code> properties.
      </li>
  </ul>

  <p><strong>FIXME</strong> - Should we provide mechanisms to edit the contents
  of a "tomcat-users.xml" file through the admin applications?</p>

  <p>Each <em>Realm</em> is owned by a parent <em>Engine</em>, <em>Host</em>,
  or <em>Context</em>.</p>

</blockquote></td></tr></table><table cellpadding="2" cellspacing="0" border="0"><tr><td bgcolor="#525D76"><font face="arial,helvetica.sanserif" color="#ffffff"><a name="Request%20Filter"><strong>Request Filter</strong></a></font></td></tr><tr><td><blockquote>

  <p><strong>FIXME</strong> - complete this entry</p>

</blockquote></td></tr></table><table cellpadding="2" cellspacing="0" border="0"><tr><td bgcolor="#525D76"><font face="arial,helvetica.sanserif" color="#ffffff"><a name="Server"><strong>Server</strong></a></font></td></tr><tr><td><blockquote>

  <p><strong>FIXME</strong> - complete this entry</p>

</blockquote></td></tr></table><table cellpadding="2" cellspacing="0" border="0"><tr><td bgcolor="#525D76"><font face="arial,helvetica.sanserif" color="#ffffff"><a name="Service"><strong>Service</strong></a></font></td></tr><tr><td><blockquote>

  <p><strong>FIXME</strong> - complete this entry</p>

</blockquote></td></tr></table></td></tr><!--FOOTER SEPARATOR--><tr><td colspan="2"><hr size="1" noshade=""></td></tr><!--PAGE FOOTER--><tr><td colspan="2"><div align="center"><font size="-1" color="#525D76"><em>
        Copyright &copy; 1999-2002, Apache Software Foundation
        </em></font></div></td></tr></table></body></html>