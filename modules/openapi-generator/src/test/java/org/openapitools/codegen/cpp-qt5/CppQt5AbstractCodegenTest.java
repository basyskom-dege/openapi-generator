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

import org.graalvm.compiler.asm.Assembler.CodeAnnotation;
import org.openapitools.codegen.CodegenConstants;
import org.openapitools.codegen.languages.CppQt5AbstractCodegen;
import org.testng.Assert;
import org.testng.annotations.Test;
import java.io.File;
import jdk.jfr.Timestamp;
import java.lang.String;
import java.util.*;
import org.openapitools.codegen.utils.ModelUtils;
import io.swagger.v3.oas.models.media.Schema;
import io.swagger.v3.oas.models.OpenAPI;



public class CppQt5AbstractCodegenTest {

    @Test
    public void testContentCompressionEnabled() throws Exception {
        final CppQt5AbstractCodegen codegen = new CppQt5AbstractCodegen();
        codegen.additionalProperties().put(CppQt5AbstractCodegen.CONTENT_COMPRESSION_ENABLED, true);
        codegen.processOpts();

        Assert.assertEquals(codegen.additionalProperties().get(CppQt5AbstractCodegen.CONTENT_COMPRESSION_ENABLED), Boolean.TRUE);
        Assert.assertEquals(codegen.isContentCompressionEnabled, true);
    }

    
    @Test
    public void testToModelImport() throws Exception {
        final CppQt5AbstractCodegen codegen = new CppQt5AbstractCodegen();
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
        final CppQt5AbstractCodegen codegen = new CppQt5AbstractCodegen();
        Assert.assertEquals(codegen.toModelFilename("testName"), camelize(codegen.getModelNamePrefix() + "_testName_" + codegen.getModelNameSuffix()));

    }

    @Test
    public void testToGetTypeDeclaration() throws Exception {

        //how to generate valid schemas?
        final CppQt5AbstractCodegen codegen = new CppQt5ClientCodegen();
        OpenAPI openAPI = new OpenAPI();
        codegen.preprocessOpenAPI(openAPI);
        codegen.processOpts();
        List<Schema> m = new ArrayList<Schema>();
        //this wont return any schema. 
        ModelUtils.getAllSchemas(openAPI).forEach(schema -> {
            m.add(schema);
            codegen.getTypeDeclaration(schema);
        });
        //check if there are any schemas
        Assert.assertEquals(m.size(),0);

        

    }

    @Test 
    public void testToVarName() throws Exception {
        final CppQt5AbstractCodegen codegen = new CppQt5AbstractCodegen();
        //using toParamName once, to cover it. It just calls toVarName...
        Assert.assertEquals(codegen.toParamName("TESTSTRING"),"teststring");
        Assert.assertEquals(codegen.toVarName("camelTest"),"camel_test");   
        Assert.assertEquals(codegen.toVarName(codegen.reservedWords().toArray()[0].toString()),codegen.escapeReservedWord(codegen.reservedWords().toArray()[0].toString()));

    }

    @Test
    public void testNeedToImport() throws Exception {
        final CppQt5AbstractCodegen codegen = new CppQt5AbstractCodegen();
        //using Boolean.TRUE leads to ambiguous Errors.
        Assert.assertEquals(codegen.needToImport("test"),true);
        Assert.assertEquals(codegen.needToImport(""),false);
        Assert.assertEquals(codegen.needToImport(codegen.defaultIncludes().toArray()[0].toString()),false);
        Assert.assertEquals(codegen.needToImport("qint32"),false);

    }

    @Test
    public void testEscapeQuotationMark() throws Exception {
        final CppQt5AbstractCodegen codegen = new CppQt5AbstractCodegen();
        Assert.assertEquals(codegen.escapeQuotationMark("testStrWithQuotationMarks\"\""),"testStrWithQuotationMarks");
    }


    @Test
    public void testEcapeUnsafeCharacters() throws Exception {
        final CppQt5AbstractCodegen codegen = new CppQt5AbstractCodegen();
        Assert.assertEquals(codegen.escapeUnsafeCharacters("testStrWithUnsafeChars*//*"),"testStrWithUnsafeChars*_//_*");
    }

    @Test
    public void testToApiName() throws Exception {
        final CppQt5AbstractCodegen codegen = new CppQt5AbstractCodegen();
        Assert.assertEquals(codegen.toApiName("test"),codegen.getModelNamePrefix()+ codegen.getApiNamePrefix()+ "Test" + codegen.getApiNameSuffix());
    }

    @Test
    public void testToModelName() throws Exception {
        final CppQt5AbstractCodegen codegen = new CppQt5AbstractCodegen();
        Assert.assertEquals(codegen.toModelName(null),codegen.getModelNamePrefix()+"UnknownModel");
        Assert.assertEquals(codegen.toModelName("bool"),"bool");
    }

    @Test
    public void testPreprocessOpenAPI() throws Exception {
        final CppQt5AbstractCodegen codegen = new CppQt5AbstractCodegen();
        OpenAPI openAPI = new OpenAPI();

        codegen.preprocessOpenAPI(openAPI);
    }

    @Test
    public void testToEnumValue() throws Exception{
        final CppQt5AbstractCodegen codegen = new CppQt5AbstractCodegen();
        Assert.assertEquals(codegen.toEnumValue("testString\n", "String"),"testString ");
    }

    @Test
    public void testisDataTypeString() throws Exception{
        final CppQt5AbstractCodegen codegen = new CppQt5AbstractCodegen();
        Assert.assertEquals(codegen.isDataTypeString("QString"),true);
    }

}