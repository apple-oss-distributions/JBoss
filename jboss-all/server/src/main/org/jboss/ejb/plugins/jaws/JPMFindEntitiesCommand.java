/*
 * JBoss, the OpenSource J2EE webOS
 *
 * Distributable under LGPL license.
 * See terms of license at gnu.org.
 */
 
package org.jboss.ejb.plugins.jaws;

import java.lang.reflect.Method;
import java.util.Collection;
import org.jboss.ejb.EntityEnterpriseContext;

/**
 * Interface for JAWSPersistenceManager FindEntities Command.
 *      
 * @author <a href="mailto:justin@j-m-f.demon.co.uk">Justin Forder</a>
 * @version $Revision: 1.8 $
 */
public interface JPMFindEntitiesCommand
{
   // Public --------------------------------------------------------
   
   public Collection execute(Method finderMethod, 
                             Object[] args, 
                             EntityEnterpriseContext ctx)
      throws Exception;
}
