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
import org.openapitools.codegen.languages.CppQt5AbstractCodegen;
import org.openapitools.codegen.*;
import org.graalvm.compiler.asm.Assembler.CodeAnnotation;
import org.openapitools.codegen.CodegenConstants;
import org.testng.Assert;
import org.testng.annotations.Test;
import org.testng.annotations.BeforeMethod  ;
import java.io.File;
import jdk.jfr.Timestamp;
import java.lang.String;
import java.util.*;
import org.openapitools.codegen.utils.ModelUtils;
import io.swagger.v3.oas.models.media.Schema;
import io.swagger.v3.oas.models.OpenAPI;
import static java.lang.System.*;


public class CppQt5AbstractCodegenTest {

    private CppQt5AbstractCodegen codegen;

    @BeforeMethod
    public void setUp() {
        codegen = new CppQt5AbstractCodegen();
    }


    @Test
    public void testContentCompressionEnabled() throws Exception {
        codegen.additionalProperties().put(CppQt5AbstractCodegen.CONTENT_COMPRESSION_ENABLED, true);
        codegen.processOpts();

        Assert.assertEquals(codegen.additionalProperties().get(CppQt5AbstractCodegen.CONTENT_COMPRESSION_ENABLED), Boolean.TRUE);
        Assert.assertEquals(codegen.isContentCompressionEnabled, true);
    }

    
    @Test
    public void testToModelImport() throws Exception {
        codegen.processOpts();
        codegen.namespaces.put("string", "std::string");
        codegen.namespaces.forEach((k,v) -> Assert.assertEquals(codegen.toModelImport(k), "using "+ v + ";"));

        codegen.systemIncludes.forEach((str) -> Assert.assertEquals(codegen.toModelImport(str), "#include <" + str + ">"));

        codegen.importMapping().put("testKey", "testValue");
        codegen.importMapping().forEach((k,v) -> Assert.assertEquals(codegen.toModelImport(k), v ));

        codegen.setModelPackage("testpackage");
        Assert.assertEquals(codegen.toModelImport("classnameStub"),"#include \"" + codegen.modelPackage().replace("::", File.separator) + File.separator + "classnameStub.h\"");

        Assert.assertEquals(codegen.toModelImport(""),null);

    }

    @Test
    public void testToModelFilename() throws Exception {
        Assert.assertEquals(codegen.toModelFilename("testName"), camelize(codegen.getModelNamePrefix() + "_testName_" + codegen.getModelNameSuffix()));

    }

    @Test
    public void testToGetTypeDeclaration() throws Exception {

        //testing multiple yaml files to cover all schema types
        OpenAPI openAPI = TestUtils.parseFlattenSpec("src/test/resources/3_0/petstore.yaml");
        openAPI.getComponents().getSchemas().forEach((k,schema) -> {

            Assert.assertNotEquals(codegen.getTypeDeclaration(schema), "");
        });

        openAPI = TestUtils.parseFlattenSpec("src/test/resources/2_0/petstore-with-fake-endpoints-models-for-testing.yaml");
        openAPI.getComponents().getSchemas().forEach((k,schema) -> {

            Assert.assertNotEquals(codegen.getTypeDeclaration(schema), "");
        });

        openAPI = TestUtils.parseFlattenSpec("src/test/resources/3_0/form-multipart-binary-array.yaml");
        openAPI.getComponents().getSchemas().forEach((k,schema) -> {

            Assert.assertNotEquals(codegen.getTypeDeclaration(schema), "");
        });
        
        openAPI = TestUtils.parseFlattenSpec("src/test/resources/3_0/allOf.yaml");
        openAPI.getComponents().getSchemas().forEach((k,schema) -> {

            Assert.assertNotEquals(codegen.getTypeDeclaration(schema), "");
        });
        
    }

    @Test
    public void testToDefaultValue() throws Exception {
        
        //testing multiple yaml files to cover all schema types (same as in "getTypeDeclaration" Test)
        OpenAPI openAPI = TestUtils.parseFlattenSpec("src/test/resources/3_0/petstore.yaml");
        openAPI.getComponents().getSchemas().forEach((k,schema) -> {

            Assert.assertNotEquals(codegen.toDefaultValue(schema), "");
        });

        openAPI = TestUtils.parseFlattenSpec("src/test/resources/2_0/petstore-with-fake-endpoints-models-for-testing.yaml");
        openAPI.getComponents().getSchemas().forEach((k,schema) -> {

            Assert.assertNotEquals(codegen.toDefaultValue(schema), "");
        });

        openAPI = TestUtils.parseFlattenSpec("src/test/resources/3_0/form-multipart-binary-array.yaml");
        openAPI.getComponents().getSchemas().forEach((k,schema) -> {

            Assert.assertNotEquals(codegen.toDefaultValue(schema), "");
        });
        
        openAPI = TestUtils.parseFlattenSpec("src/test/resources/3_0/allOf.yaml");
        openAPI.getComponents().getSchemas().forEach((k,schema) -> {

            Assert.assertNotEquals(codegen.toDefaultValue(schema), "");
        });
        
    }   

    @Test(description = "correctly produces imports with import mapping")
    public void testPostProcessOperationsWithModelsTestWithImportMapping() {
        //generate Import Mapping
        final String importName = "QString";
        Map<String, Object> operations = createPostProcessOperationsMapWithImportName(importName);
        //generate Models. This wont give the model we need...
        List<Object> allModels = new ArrayList<>();
        OpenAPI openAPI = TestUtils.parseFlattenSpec("src/test/resources/3_0/petstore.yaml");
        openAPI.getComponents().getSchemas().forEach((string,schema) -> {
            allModels.add((Object)codegen.fromModel(string, schema));
            });

        //run Function to test with emptyList because CodegenModel cannot be casted to Map...
        Map<String, Object> value = codegen.postProcessOperationsWithModels(operations, Collections.emptyList());
        List<Map<String, Object>> extractedImports = (List<Map<String, Object>>) operations.get("imports");
        
        
        Assert.assertEquals("[{import=QString, classname=testClass}, {import=#include \"testReturnBaseType.h\"}, {import=#include <QString>}]",value.get("imports").toString());
        //Operations are too big to check...
        Assert.assertNotEquals(value.get("operations").toString(),"");
        Assert.assertEquals(value.size(), 2);
    }
    
    private Map<String, Object> createPostProcessOperationsMapWithImportName(String importName) {
        List<CodegenOperation> ops = new ArrayList<>();
        //generate some operations
        CodegenOperation e = new CodegenOperation();
        e.returnBaseType = "testReturnBaseType";

        //generate some parameters
        List<CodegenParameter> allParams = new ArrayList<>();   
        CodegenParameter p = new CodegenParameter();
        p.baseType = "qint64";
        p.isPrimitiveType = true;
        allParams.add(p);
        //add parameter to operations
        e.allParams = allParams;
        
        //add to operations
        ops.add(e);
        
        Map<String, Object> operations = new HashMap<String, Object>() {{
            put("operation", ops);
            put("classname", "testClass");
        }};

        Map<String, Object> importList = new HashMap<String, Object>() {{
            put("import", importName);
            put("classname", "testClass");
        }};
        List<Map<String, Object>> imports = new ArrayList<>();
        imports.add(importList);
        return new HashMap<String, Object>() {{
            put("operations", operations);
            put("imports", imports);
        }};
    }

    @Test 
    public void testToVarName() throws Exception {
        //using toParamName once, to cover it. It just calls toVarName...
        Assert.assertEquals(codegen.toParamName("TESTSTRING"),"teststring");
        Assert.assertEquals(codegen.toVarName("camelTest"),"camel_test");   
        Assert.assertEquals(codegen.toVarName(codegen.reservedWords().toArray()[0].toString()),codegen.escapeReservedWord(codegen.reservedWords().toArray()[0].toString()));

    }

    @Test
    public void testNeedToImport() throws Exception {
        //using Boolean.TRUE leads to ambiguous Errors.
        Assert.assertEquals(codegen.needToImport("test"),true);
        Assert.assertEquals(codegen.needToImport(""),false);
        Assert.assertEquals(codegen.needToImport(codegen.defaultIncludes().toArray()[0].toString()),false);
        Assert.assertEquals(codegen.needToImport("qint32"),false);

    }

    @Test
    public void testEscapeQuotationMark() throws Exception {
        Assert.assertEquals(codegen.escapeQuotationMark("testStrWithQuotationMarks\"\""),"testStrWithQuotationMarks");
    }


    @Test
    public void testEcapeUnsafeCharacters() throws Exception {
        Assert.assertEquals(codegen.escapeUnsafeCharacters("testStrWithUnsafeChars*//*"),"testStrWithUnsafeChars*_//_*");
    }

    @Test
    public void testToApiName() throws Exception {
        Assert.assertEquals(codegen.toApiName("test"),codegen.getModelNamePrefix()+ codegen.getApiNamePrefix()+ "Test" + codegen.getApiNameSuffix());
    }

    @Test
    public void testToModelName() throws Exception {
        Assert.assertEquals(codegen.toModelName(null),codegen.getModelNamePrefix()+"UnknownModel");
        Assert.assertEquals(codegen.toModelName("bool"),"bool");
    }

    @Test
    public void testPreprocessOpenAPI() throws Exception {
        OpenAPI openAPI = new OpenAPI();

        codegen.preprocessOpenAPI(openAPI);
    }

    @Test
    public void testToEnumValue() throws Exception{
        Assert.assertEquals(codegen.toEnumValue("testString\n", "String"),"testString ");
    }

    @Test
    public void testisDataTypeString() throws Exception{
        Assert.assertEquals(codegen.isDataTypeString("QString"),true);
    }

}