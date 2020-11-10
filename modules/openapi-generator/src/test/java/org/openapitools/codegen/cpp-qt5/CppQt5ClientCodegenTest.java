/*
 * Copyright 2018 OpenAPI-Generator Contributors (https://openapi-generator.tech)
 * Copyright 2018 SmartBear Software
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     https://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

//selected all language packages for have access to protected variables
package org.openapitools.codegen.languages;

import static org.openapitools.codegen.utils.StringUtils.*;
import org.openapitools.codegen.CodegenConstants;
import org.openapitools.codegen.languages.CppQt5ClientCodegen;
import org.testng.Assert;
import org.testng.annotations.Test;
import java.io.File;
import jdk.jfr.Timestamp;
import java.lang.String;


public class CppQt5ClientCodegenTest {

    @Test
    public void testInitialConfigValues() throws Exception {
        final CppQt5ClientCodegen codegen = new CppQt5ClientCodegen();
        codegen.processOpts();

        Assert.assertEquals(codegen.additionalProperties().get(CodegenConstants.HIDE_GENERATION_TIMESTAMP), Boolean.TRUE);
        Assert.assertEquals(codegen.isHideGenerationTimestamp(), true);
    }

    @Test
    public void testSettersForConfigValues() throws Exception {
        final CppQt5ClientCodegen codegen = new CppQt5ClientCodegen();
        codegen.setHideGenerationTimestamp(false);
        codegen.processOpts();

        Assert.assertEquals(codegen.additionalProperties().get(CodegenConstants.HIDE_GENERATION_TIMESTAMP), Boolean.FALSE);
        Assert.assertEquals(codegen.isHideGenerationTimestamp(), false);
    }

    @Test
    public void testAdditionalPropertiesPutForConfigValues() throws Exception {
        final CppQt5ClientCodegen codegen = new CppQt5ClientCodegen();
        codegen.additionalProperties().put(CodegenConstants.HIDE_GENERATION_TIMESTAMP, false);
        codegen.processOpts();

        Assert.assertEquals(codegen.additionalProperties().get(CodegenConstants.HIDE_GENERATION_TIMESTAMP), Boolean.FALSE);
        Assert.assertEquals(codegen.isHideGenerationTimestamp(), false);
    }

    @Test
    public void testGetHelp() throws Exception {
        final CppQt5ClientCodegen codegen = new CppQt5ClientCodegen();
        Assert.assertEquals(codegen.getHelp(), "Generates a Qt5 C++ client library.");
    }

    @Test
    public void testAdditionalPropertiesOptionalProjectFile() throws Exception {
        final CppQt5ClientCodegen codegen = new CppQt5ClientCodegen();
        codegen.additionalProperties().put(CodegenConstants.OPTIONAL_PROJECT_FILE, true);
        codegen.processOpts();

        Assert.assertEquals(codegen.additionalProperties().get(CodegenConstants.OPTIONAL_PROJECT_FILE), Boolean.TRUE);
        //protected variable
        Assert.assertEquals(codegen.optionalProjectFileFlag, true);

    }    

    @Test
    public void testAdditionalPropertiesmodelNamePrefix() throws Exception {
        final CppQt5ClientCodegen codegen = new CppQt5ClientCodegen();
        codegen.additionalProperties().put(CodegenConstants.MODEL_NAME_PREFIX, "modelNamePrefix");
        codegen.additionalProperties().put(CodegenConstants.OPTIONAL_PROJECT_FILE, true);

        codegen.processOpts();

        Assert.assertEquals(codegen.additionalProperties().get(CodegenConstants.OPTIONAL_PROJECT_FILE), Boolean.TRUE);
        Assert.assertEquals(codegen.additionalProperties().get(CodegenConstants.MODEL_NAME_PREFIX), "modelNamePrefix");
        //protected variable
        Assert.assertEquals(codegen.optionalProjectFileFlag, true);
        Assert.assertTrue(codegen.supportingFiles().size() > 0);

    }    

    @Test
    public void testModelFileFolder() throws Exception {
        final CppQt5ClientCodegen codegen = new CppQt5ClientCodegen();
        Assert.assertEquals(codegen.modelFileFolder(), codegen.outputFolder()+ "/" + codegen.sourceFolder + "/" + codegen.modelPackage().replace("::", File.separator));

    }

    @Test
    public void testApiFileFolder() throws Exception {
        final CppQt5ClientCodegen codegen = new CppQt5ClientCodegen();
        Assert.assertEquals(codegen.apiFileFolder(),codegen.outputFolder() + "/" + codegen.sourceFolder + "/" + codegen.apiPackage().replace("::", File.separator));
        
    }

    @Test
    public void testToApiFilename() throws Exception {
        final CppQt5ClientCodegen codegen = new CppQt5ClientCodegen();
        //put "test" as name argument of the function
        Assert.assertEquals(codegen.toApiFilename("test"), codegen.getModelNamePrefix()+ codegen.sanitizeName(camelize("test")) + "Api");
        
    }

}