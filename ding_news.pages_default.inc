<?php
/**
 * @file
 * ding_news.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function ding_news_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass;
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'News story',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'css_id' => '',
    'css' => '',
    'contexts' => array(
      0 => array(
        'identifier' => 'User',
        'keyword' => 'user',
        'name' => 'user',
        'type' => 'current',
        'uid' => NULL,
        'id' => 1,
      ),
    ),
    'relationships' => array(
      0 => array(
        'identifier' => 'OG group from news node',
        'keyword' => 'group',
        'name' => 'og_group_from_node',
        'context' => 'argument_entity_id:node_1',
        'id' => 1,
      ),
      1 => array(
        'identifier' => 'Library node from OG group',
        'keyword' => 'library',
        'name' => 'og_node_from_group',
        'context' => 'relationship_og_group_from_node_1',
        'id' => 1,
      ),
      2 => array(
        'identifier' => 'All terms from node',
        'keyword' => 'terms',
        'name' => 'terms_from_node',
        'context' => 'argument_entity_id:node_1',
        'vid' => array(
          1 => '1',
          2 => '2',
        ),
        'concatenator' => ',',
        'id' => 1,
      ),
      3 => array(
        'identifier' => 'Category terms from node being viewed',
        'keyword' => 'taxonomy_term',
        'name' => 'entity_from_field:field_category-node-taxonomy_term',
        'context' => 'argument_entity_id:node_1',
        'id' => 1,
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'ding_news' => 'ding_news',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'panels_breadcrumbs_state' => 1,
    'panels_breadcrumbs_titles' => 'News
%node:title',
    'panels_breadcrumbs_paths' => '<none>
<none>',
  );
  $display = new panels_display;
  $display->layout = 'threecol_25_50_25';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'middle' => NULL,
      'right' => NULL,
      'top' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass;
  $pane->pid = 'new-1';
  $pane->panel = 'left';
  $pane->type = 'category_menu';
  $pane->subtype = 'category_menu';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'url_settings_all_categories' => NULL,
    'url_settings' => NULL,
    'context' => array(
      0 => 'relationship_entity_from_field:field_category-node-taxonomy_term_1',
      1 => 'relationship_og_node_from_group_1',
      2 => 'empty',
    ),
    'override_title' => 0,
    'override_title_text' => '',
    'type' => 'news',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = '';
  $display->content['new-1'] = $pane;
  $display->panels['left'][0] = 'new-1';
  $pane = new stdClass;
  $pane->pid = 'new-2';
  $pane->panel = 'middle';
  $pane->type = 'node_content';
  $pane->subtype = 'node_content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'links' => 1,
    'no_extras' => 0,
    'override_title' => 0,
    'override_title_text' => '',
    'identifier' => '',
    'link' => 0,
    'leave_node_title' => 1,
    'build_mode' => 'full',
    'context' => 'argument_entity_id:node_1',
  );
  $pane->cache = array(
    'method' => 'rules',
    'settings' => array(
      'granularity' => 'context',
      'language' => 1,
      'cache_key' => 'panel_context:node_view:node_view_panel_context',
    ),
  );
  $pane->style = array(
    'settings' => NULL,
    'style' => 'naked',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = '';
  $display->content['new-2'] = $pane;
  $display->panels['middle'][0] = 'new-2';
  $pane = new stdClass;
  $pane->pid = 'new-3';
  $pane->panel = 'right';
  $pane->type = 'campaign';
  $pane->subtype = 'campaign';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'ding_campaign_count' => 3,
    'ding_campaign_offset' => 0,
    'context' => array(
      0 => 'argument_entity_id:node_1',
      1 => 'relationship_og_node_from_group_1',
      2 => 'empty',
      3 => 'relationship_terms_from_node_1',
    ),
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array(
    'method' => 'simple',
    'settings' => array(
      'lifetime' => '600',
      'granularity' => 'context',
    ),
  );
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = '';
  $display->content['new-3'] = $pane;
  $display->panels['right'][0] = 'new-3';
  $pane = new stdClass;
  $pane->pid = 'new-4';
  $pane->panel = 'right';
  $pane->type = 'block';
  $pane->subtype = 'similarterms-ding_content_tags';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = '';
  $display->content['new-4'] = $pane;
  $display->panels['right'][1] = 'new-4';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function ding_news_default_page_manager_pages() {
  $page = new stdClass;
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'ding_news_library';
  $page->task = 'page';
  $page->admin_title = 'Library news page';
  $page->admin_description = '';
  $page->path = 'node/%node/news/!tid';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'access content',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array(
    'node' => array(
      'id' => 1,
      'identifier' => 'Library node',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
    'tid' => array(
      'id' => 1,
      'identifier' => 'Category term',
      'name' => 'term',
      'settings' => array(
        'input_form' => 'term',
        'vids' => array(
          1 => '1',
          2 => 0,
        ),
        'breadcrumb' => 0,
      ),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass;
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_ding_news_library_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'ding_news_library';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Library news',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'OG group from library node',
        'keyword' => 'group',
        'name' => 'og_group_from_node',
        'context' => 'argument_entity_id:node_1',
        'id' => 1,
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'ding_library' => 'ding_library',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'og_is_node_group',
          'settings' => NULL,
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'panels_breadcrumbs_state' => 1,
    'panels_breadcrumbs_titles' => 'Libraries
%node:title
News
%tid:name
',
    'panels_breadcrumbs_paths' => 'libraries
node/%node:nid
node/%node:nid/news
<none>',
  );
  $display = new panels_display;
  $display->layout = 'threecol_25_50_25_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'middle' => NULL,
      'right' => NULL,
      'top' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass;
  $pane->pid = 'new-11';
  $pane->panel = 'left';
  $pane->type = 'category_menu';
  $pane->subtype = 'category_menu';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => 'news',
    'context' => array(
      0 => 'argument_term_1',
      1 => 'argument_entity_id:node_1',
    ),
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = '';
  $display->content['new-11'] = $pane;
  $display->panels['left'][0] = 'new-11';
  $pane = new stdClass;
  $pane->pid = 'new-12';
  $pane->panel = 'middle';
  $pane->type = 'menu_title';
  $pane->subtype = 'menu_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = '';
  $display->content['new-12'] = $pane;
  $display->panels['middle'][0] = 'new-12';
  $pane = new stdClass;
  $pane->pid = 'new-13';
  $pane->panel = 'middle';
  $pane->type = 'library_list';
  $pane->subtype = 'library_list';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => 'news',
    'context' => array(
      0 => 'argument_term_1',
      1 => 'argument_entity_id:node_1',
    ),
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = '';
  $display->content['new-13'] = $pane;
  $display->panels['middle'][1] = 'new-13';
  $pane = new stdClass;
  $pane->pid = 'new-14';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'ding_news-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'argument_entity_id:node_1',
      1 => 'argument_term_1',
    ),
  );
  $pane->cache = array(
    'method' => 'rules',
    'settings' => array(
      'granularity' => 'context',
      'language' => 1,
      'cache_key' => 'panel_context:page-ding_news_library:page_ding_news_library_panel_context',
    ),
  );
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = '';
  $display->content['new-14'] = $pane;
  $display->panels['middle'][2] = 'new-14';
  $pane = new stdClass;
  $pane->pid = 'new-15';
  $pane->panel = 'right';
  $pane->type = 'campaign';
  $pane->subtype = 'campaign';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'ding_campaign_count' => 3,
    'ding_campaign_offset' => 0,
    'context' => array(
      0 => 'empty',
      1 => 'relationship_og_node_from_group_1',
      2 => 'empty',
      3 => 'empty',
    ),
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = '';
  $display->content['new-15'] = $pane;
  $display->panels['right'][0] = 'new-15';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['ding_news_library'] = $page;

  return $pages;

}
