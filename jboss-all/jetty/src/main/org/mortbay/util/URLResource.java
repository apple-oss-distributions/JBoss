// ===========================================================================
// Copyright (c) 1996 Mort Bay Consulting Pty. Ltd. All rights reserved.
// $Id: URLResource.java,v 1.3.2.4 2003/06/04 04:47:59 starksm Exp $
// ---------------------------------------------------------------------------
package org.mortbay.util;

import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLConnection;
import java.security.Permission;

/* ------------------------------------------------------------ */
/** Abstract resource class.
 *
 * @version $Id: URLResource.java,v 1.3.2.4 2003/06/04 04:47:59 starksm Exp $
 * @author Nuno Pregui?a
 * @author Greg Wilkins (gregw)
 */
public class URLResource extends Resource
{
    protected URL _url;
    protected String _urlString;
    protected transient URLConnection _connection;
    protected transient InputStream _in=null;
    
    /* ------------------------------------------------------------ */
    protected URLResource(URL url, URLConnection connection)
    {
        _url = url;
        _urlString=_url.toString();
        _connection=connection;
    }

    /* ------------------------------------------------------------ */
    protected synchronized boolean checkConnection()
    {
        if (_connection==null)
        {
            try{
                _connection=_url.openConnection();
            }
            catch(IOException e)
            {
                e.printStackTrace();
                Code.ignore(e);
            }
        }
        return _connection!=null;
    }

    /* ------------------------------------------------------------ */
    /** Release any resources held by the resource.
     */
    public synchronized void release()
    {
        if (_in!=null)
        {
            try{_in.close();}catch(IOException e){Code.ignore(e);}
            _in=null;
        }

        if (_connection!=null)
            _connection=null;
    }

    /* ------------------------------------------------------------ */
    /**
     * Returns true if the respresened resource exists.
     */
    public boolean exists()
    {
        try
        {
            if (checkConnection() && _in==null )
            {
                synchronized(this)
                {
                    if ( _in==null )
                        _in = _connection.getInputStream();
                }
            }
        }
        catch (IOException e)
        {
            Code.ignore(e);
        }
        return _in!=null;
    }

    /* ------------------------------------------------------------ */
    /**
     * Returns true if the respresenetd resource is a container/directory.
     * If the resource is not a file, resources ending with "/" are
     * considered directories.
     */
    public boolean isDirectory()
    {
        return exists() && _url.toString().endsWith("/");
    }


    /* ------------------------------------------------------------ */
    /**
     * Returns the last modified time
     */
    public long lastModified()
    {
        if (checkConnection())
            return _connection.getLastModified();
        return -1;
    }


    /* ------------------------------------------------------------ */
    /**
     * Return the length of the resource
     */
    public long length()
    {
        if (checkConnection())
            return _connection.getContentLength();
        return -1;
    }

    /* ------------------------------------------------------------ */
    /**
     * Returns an URL representing the given resource
     */
    public URL getURL()
    {
        return _url;
    }

    /* ------------------------------------------------------------ */
    /**
     * Returns an File representing the given resource or NULL if this
     * is not possible.
     */
    public File getFile()
        throws IOException
    {
        // Try the permission hack
        if (checkConnection())
        {
            Permission perm = _connection.getPermission();
            if (perm instanceof java.io.FilePermission)
                return new File(perm.getName());
        }

        // Try the URL file arg
        try {return new File(_url.getFile());}
        catch(Exception e) {Code.ignore(e);}

        // Don't know the file
        return null;    
    }

    /* ------------------------------------------------------------ */
    /**
     * Returns the name of the resource
     */
    public String getName()
    {
        return _url.toExternalForm();
    }

    /* ------------------------------------------------------------ */
    /**
     * Returns an input stream to the resource
     */
    public synchronized InputStream getInputStream()
        throws java.io.IOException
    {
        if (!checkConnection())
            throw new IOException( "Invalid resource");

        try
        {    
            if( _in != null)
            {
                InputStream in = _in;
                _in=null;
                return in;
            }
            return _connection.getInputStream();
        }
        finally
        {
            _connection=null;
        }
    }


    /* ------------------------------------------------------------ */
    /**
     * Returns an output stream to the resource
     */
    public OutputStream getOutputStream()
        throws java.io.IOException, SecurityException
    {
        throw new IOException( "Output not supported");
    }

    /* ------------------------------------------------------------ */
    /**
     * Deletes the given resource
     */
    public boolean delete()
        throws SecurityException
    {
        throw new SecurityException( "Delete not supported");
    }

    /* ------------------------------------------------------------ */
    /**
     * Rename the given resource
     */
    public boolean renameTo( Resource dest)
        throws SecurityException
    {
        throw new SecurityException( "RenameTo not supported");
    }

    /* ------------------------------------------------------------ */
    /**
     * Returns a list of resource names contained in the given resource
     */
    public String[] list()
    {
        return null;
    }

    /* ------------------------------------------------------------ */
    /**
     * Returns the resource contained inside the current resource with the
     * given name
     */
    public Resource addPath(String path)
        throws IOException,MalformedURLException
    {
        if (path==null)
            return null;

        path = URI.canonicalPath(path);

        return newResource(URI.addPaths(_url.toExternalForm(),path));
    }

    /* ------------------------------------------------------------ */
    public String toString()
    {
        return _urlString;
    }

    /* ------------------------------------------------------------ */
    public int hashCode()
    {
        return _url.hashCode();
    }
    
    /* ------------------------------------------------------------ */
    public boolean equals( Object o)
    {
        return o instanceof URLResource &&
            _url.equals(((URLResource)o)._url);
    }

}
