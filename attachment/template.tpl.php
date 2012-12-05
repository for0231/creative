<?php 
/**
 * page callback: search
 *
 * Available variables:
 *
 * - $nodes: node对象数组
 * - $category: 商品分类名称
 * 
 * @author Huhj
 * @since 2012-06-27
 */
$breadcrumb = $variables['breadcrumb'];
$catalog_attributes = $variables['catalog_attributes'];
$group_attributes = $variables['group_attribute'];
$showtype = isset($_GET['showtype']) ? $_GET['showtype'] : '1';
function _get_attr_parameter($aid) {
  $p_attr = isset($_GET['attr']) ? $_GET['attr'] : '';
  if (empty($p_attr)) {
    return null;
  }
  $attr_groups = explode("--", $p_attr);  
  foreach ($attr_groups as $group) {
    $parameters = explode('-', $group);
    if ($aid == $parameters[0]){
       return $parameters;     
    }
  }
  return null;
}
function _get_g_attr_parameter() { // 组属性选择
  $p_attr = isset($_GET['groupattr']) ? $_GET['groupattr'] : '';
  if (empty($p_attr)) {
    return null;
  }
  $attr_groups = explode("--", $p_attr);  
  foreach ($attr_groups as $group) {
    $parameters = explode('-', $group);
    drupal_debug($parameters);
    //if ($aid == $parameters[0]){
    //   return $parameters;     
    //}
  }
  return null;
}
drupal_add_js('plugins/pages/search/templates/' . $variables['page_template'] . '/page-search.js');
?>
<?php print block('topnav') ?>
<?php print block('header') ?>
<section id="main-content" class="container_16">
  <div class="grid_3">
    <div class='inside'>
      <?php print block('product_view_history') ?>
    </div>
  </div>
  <div class="grid_13">
    <div class='inside'>
      <div class="search-nav">
        <?php print $breadcrumb ?>       
      </div>
      <?php if (count($catalog_attributes) > 0) { ?>
      <div class="attr-box">
        <?php if (isset($_GET['attr']) || isset($_GET['groupattr'])) { ?>
        <div class="title">
           <dl class="clearfix">
             <dt>你选择了：</dt>
             <?php foreach ($catalog_attributes as $attr) { ?>
             <?php $parameter = _get_attr_parameter($attr->aid) ?>
             <?php if (!is_null($parameter)) { ?>
             <?php $attr_option = uc_attribute_option_load($parameter[1]) ?>
             <dd> 
               <a class="delete-select" href="<?php echo url('search', array('query' => ec_product_url_query_del('attr', $parameter[0] . '-' . $attr_option->oid))) ?>">
                 <span><?php echo $attr->name . ':' . $attr_option->name ?></span>
                 <sup>x</sup>
               </a>
             </dd>
             <?php } } ?>

            <!--组属性 已选择项 开始-->
             <?php foreach ($group_attributes as $key => $value) {?>
             <?php $parameter = _get_g_attr_parameter();?>
             <?php if (!is_null($parameter)) { ?>
             <?php $option = uc_attribute_option_load($parameter[1]) ?>
             <dd> 
               <a class="delete-select" href="<?php echo url('search', array('query' => ec_product_url_query_del('groupattr', $parameter[0] . '-' . $option->oid))) ?>">
                 <span><?php echo $key . ':' . $option->name ?></span>
                 <sup>x</sup>
               </a>
             </dd>
            <?php } } ?>
            <!--组属性 已选择项 结束-->
           </dl>
        </div>
        <?php } ?>
        <div class="arrt-list">
        <?php $row = 0; ?>
        <?php foreach ($catalog_attributes as $attr) { ?>
        <?php $parameter = _get_attr_parameter($attr->aid) ?>
        <?php if (is_null($parameter)) { ?>
        <?php
          $options = db_select('uc_attribute_options', 'o')
            ->fields('o', array('oid', 'aid', 'name'))
            ->condition('aid', $attr->aid)
            ->execute(); 
          $row++;
        ?>
       
        <dl class="clearfix">
          <dt><?php echo $attr->name ?>：</dt>
          <dd>
          <?php foreach ($options as $option) { ?>
          <?php echo l($option->name, 'search', array('query' => ec_product_url_query('attr', $attr->aid . '-' . $option->oid))) ?>
          <?php } ?> 
          </dd>
        </dl> 
        <?php } } ?>
         <!--组属性开始-->
        <?php $row_group = 0; ?>
        <?php foreach ($group_attributes as $key => $values) { ?>
        <?php // if (is_null($parameter)) { ?>
        <?php
          /*$options = db_select('uc_attribute_options', 'o')
            ->fields('o', array('oid', 'aid', 'name'))
            ->condition('aid', $attr->aid)
            ->execute(); */
          $row_group++;
        ?>
        <dl class="clearfix">
          <dt><?php echo $key ?>：</dt>
          <dd>
          <?php foreach ($values as $option) { ?>
          <?php echo l($option->name, 'search', array('query' => ec_product_url_query('groupattr', $option->vid . '-' . $option->tid))) ?>
          <?php } ?> 
          </dd>
        </dl> 
        <?php  } ?>
        <?php //} ?>
        <!--组属性结束-->
        </div>
        <?php if ($row > 0 || $row_group > 0) { ?>
        <div class="selectitemmore" style="display: block;">
          <p class="OpenMore" style="display: none;">↓展开</p>
          <p class="CloseMore" style="display: block;">↑收起</p>
        </div>
        <?php } ?>
      </div>
      <?php } ?>
      <?php 
      if ($showtype == '1') {
        print block('product_list');
      } else if ($showtype == '2') { 
        print block('product_list','default', 'list');
      } else if ($showtype == '3') { 
        print block('product_list');
      } else {
        print block('product_list');
      }
      ?>
    </div>
  </div>
</section>

<footer id="footer">
<?php print block('footer');?>
</footer>
