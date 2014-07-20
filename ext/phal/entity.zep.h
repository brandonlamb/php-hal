
extern zend_class_entry *phal_entity_ce;

ZEPHIR_INIT_CLASS(Phal_Entity);

PHP_METHOD(Phal_Entity, __construct);
PHP_METHOD(Phal_Entity, setId);
PHP_METHOD(Phal_Entity, getId);
PHP_METHOD(Phal_Entity, setRepositoryKey);
PHP_METHOD(Phal_Entity, getRepositoryKey);
PHP_METHOD(Phal_Entity, setTitle);
PHP_METHOD(Phal_Entity, getTitle);
PHP_METHOD(Phal_Entity, setUri);
PHP_METHOD(Phal_Entity, getUri);
PHP_METHOD(Phal_Entity, setData);
PHP_METHOD(Phal_Entity, addData);
PHP_METHOD(Phal_Entity, getData);
PHP_METHOD(Phal_Entity, setLink);
PHP_METHOD(Phal_Entity, setLinks);
PHP_METHOD(Phal_Entity, linkResource);
PHP_METHOD(Phal_Entity, linkResources);
PHP_METHOD(Phal_Entity, throwExceptionIfNotLinkableResouce);
PHP_METHOD(Phal_Entity, expandLinkedResourcesTree);
PHP_METHOD(Phal_Entity, expandLinkedResources);
PHP_METHOD(Phal_Entity, getAllLinkedResources);
PHP_METHOD(Phal_Entity, getLinkedResources);
PHP_METHOD(Phal_Entity, getAllLinks);
PHP_METHOD(Phal_Entity, getLinks);
PHP_METHOD(Phal_Entity, addResource);
PHP_METHOD(Phal_Entity, addResources);
PHP_METHOD(Phal_Entity, getAllResources);
PHP_METHOD(Phal_Entity, getResources);
PHP_METHOD(Phal_Entity, getSelfLink);
PHP_METHOD(Phal_Entity, setLastUpdate);
PHP_METHOD(Phal_Entity, getLastUpdate);
PHP_METHOD(Phal_Entity, setCache);
PHP_METHOD(Phal_Entity, getCache);
PHP_METHOD(Phal_Entity, setFormatWriter);
PHP_METHOD(Phal_Entity, getFormatWriter);
PHP_METHOD(Phal_Entity, __toString);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_entity_setid, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_entity_setrepositorykey, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_entity_settitle, 0, 0, 1)
	ZEND_ARG_INFO(0, title)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_entity_seturi, 0, 0, 1)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_entity_setdata, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_entity_adddata, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_entity_setlink, 0, 0, 2)
	ZEND_ARG_INFO(0, rel)
	ZEND_ARG_INFO(0, link)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_entity_setlinks, 0, 0, 2)
	ZEND_ARG_INFO(0, rel)
	ZEND_ARG_INFO(0, links)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_entity_linkresource, 0, 0, 2)
	ZEND_ARG_INFO(0, rel)
	ZEND_ARG_INFO(0, resource)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_entity_linkresources, 0, 0, 2)
	ZEND_ARG_INFO(0, rel)
	ZEND_ARG_INFO(0, resources)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_entity_throwexceptionifnotlinkableresouce, 0, 0, 1)
	ZEND_ARG_INFO(0, resource)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_entity_expandlinkedresourcestree, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_entity_expandlinkedresources, 0, 0, 1)
	ZEND_ARG_INFO(0, rel)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_entity_getlinkedresources, 0, 0, 1)
	ZEND_ARG_INFO(0, rel)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_entity_getlinks, 0, 0, 1)
	ZEND_ARG_INFO(0, rel)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_entity_addresource, 0, 0, 2)
	ZEND_ARG_INFO(0, rel)
	ZEND_ARG_INFO(0, resource)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_entity_addresources, 0, 0, 2)
	ZEND_ARG_INFO(0, rel)
	ZEND_ARG_INFO(0, resources)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_entity_getresources, 0, 0, 1)
	ZEND_ARG_INFO(0, rel)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_entity_setlastupdate, 0, 0, 1)
	ZEND_ARG_INFO(0, date)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_entity_setcache, 0, 0, 1)
	ZEND_ARG_INFO(0, secs)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phal_entity_setformatwriter, 0, 0, 1)
	ZEND_ARG_INFO(0, writer)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phal_entity_method_entry) {
	PHP_ME(Phal_Entity, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phal_Entity, setId, arginfo_phal_entity_setid, ZEND_ACC_PUBLIC)
	PHP_ME(Phal_Entity, getId, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phal_Entity, setRepositoryKey, arginfo_phal_entity_setrepositorykey, ZEND_ACC_PUBLIC)
	PHP_ME(Phal_Entity, getRepositoryKey, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phal_Entity, setTitle, arginfo_phal_entity_settitle, ZEND_ACC_PUBLIC)
	PHP_ME(Phal_Entity, getTitle, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phal_Entity, setUri, arginfo_phal_entity_seturi, ZEND_ACC_PUBLIC)
	PHP_ME(Phal_Entity, getUri, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phal_Entity, setData, arginfo_phal_entity_setdata, ZEND_ACC_PUBLIC)
	PHP_ME(Phal_Entity, addData, arginfo_phal_entity_adddata, ZEND_ACC_PUBLIC)
	PHP_ME(Phal_Entity, getData, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phal_Entity, setLink, arginfo_phal_entity_setlink, ZEND_ACC_PUBLIC)
	PHP_ME(Phal_Entity, setLinks, arginfo_phal_entity_setlinks, ZEND_ACC_PUBLIC)
	PHP_ME(Phal_Entity, linkResource, arginfo_phal_entity_linkresource, ZEND_ACC_PUBLIC)
	PHP_ME(Phal_Entity, linkResources, arginfo_phal_entity_linkresources, ZEND_ACC_PUBLIC)
	PHP_ME(Phal_Entity, throwExceptionIfNotLinkableResouce, arginfo_phal_entity_throwexceptionifnotlinkableresouce, ZEND_ACC_PROTECTED)
	PHP_ME(Phal_Entity, expandLinkedResourcesTree, arginfo_phal_entity_expandlinkedresourcestree, ZEND_ACC_PUBLIC)
	PHP_ME(Phal_Entity, expandLinkedResources, arginfo_phal_entity_expandlinkedresources, ZEND_ACC_PUBLIC)
	PHP_ME(Phal_Entity, getAllLinkedResources, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phal_Entity, getLinkedResources, arginfo_phal_entity_getlinkedresources, ZEND_ACC_PUBLIC)
	PHP_ME(Phal_Entity, getAllLinks, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phal_Entity, getLinks, arginfo_phal_entity_getlinks, ZEND_ACC_PUBLIC)
	PHP_ME(Phal_Entity, addResource, arginfo_phal_entity_addresource, ZEND_ACC_PUBLIC)
	PHP_ME(Phal_Entity, addResources, arginfo_phal_entity_addresources, ZEND_ACC_PUBLIC)
	PHP_ME(Phal_Entity, getAllResources, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phal_Entity, getResources, arginfo_phal_entity_getresources, ZEND_ACC_PUBLIC)
	PHP_ME(Phal_Entity, getSelfLink, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phal_Entity, setLastUpdate, arginfo_phal_entity_setlastupdate, ZEND_ACC_PUBLIC)
	PHP_ME(Phal_Entity, getLastUpdate, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phal_Entity, setCache, arginfo_phal_entity_setcache, ZEND_ACC_PUBLIC)
	PHP_ME(Phal_Entity, getCache, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phal_Entity, setFormatWriter, arginfo_phal_entity_setformatwriter, ZEND_ACC_PUBLIC)
	PHP_ME(Phal_Entity, getFormatWriter, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phal_Entity, __toString, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
