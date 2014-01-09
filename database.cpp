/**
* @file database.cpp
* @brief MYSQL数据库接口
* @author nvng and fU9ANg
* @version v1.0
* @date 2014-01-03
*/

#include "database.h"

DataBase* DataBase::pinstance = NULL;

/**
* @brief 
*
* @param host
* @param user_name
* @param password
* @param database
*
* @return 
*/
bool DataBase::Init (string host, string user_name, string password, string database)
{
    m_host      = host;
    m_user_name = user_name;
    m_password  = password;
    m_database  = database;

    try
    {
        m_pDriver = get_driver_instance ();
        m_pConn = m_pDriver->connect (m_host, m_user_name, m_password);
        m_pConn->setSchema (database);
    }
    catch (SQLException e)
    {
        LOG(ERROR) << e.what ();
        printf ("Database Info =[%s]\n", e.what ());
        m_pConn = NULL;
    }
    return  (NULL == m_pConn) ? false:true;
}

/**
* @brief 
*/
DataBase::DataBase ()
{
    m_pConn = NULL;
}

/**
* @brief 
*/
DataBase::~DataBase ()
{
    if  (NULL != m_pConn)
    {
        delete m_pConn;
        m_pConn = NULL;
    }
}

/**
* @brief 
*
* @return 
*/
Connection* DataBase::getConnection ()
{
    return m_pConn;	
}

/**
* @brief 
*
* @return 
*/
Statement* DataBase::getStatement ()
{
    Statement* p = NULL;
    try
    {
        p = m_pConn->createStatement (); 
    }
    catch  (SQLException e)
    {
        LOG(ERROR) << e.what ();
        if (NULL != p )
        {
            delete p;
            p = NULL;
        }
    }
    return p;
}

/**
* @brief 
*
* @param sql
*
* @return 
*/
PreparedStatement* DataBase::preStatement (string sql)
{
    return m_pConn->prepareStatement (sql); 
}

/**
* @brief 
*
* @return 
*/
DataBase* DataBase::instance ()
{
    if  ( NULL == pinstance)
    {
        pinstance = new DataBase ();
    }
    return pinstance;
}
