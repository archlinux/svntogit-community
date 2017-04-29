# $Id$
# Maintainer: BlackEagle < ike DOT devolder AT gmail DOT com >
# Contributor: Bram Schoenmakers <me@bramschoenmakers.nl>
pkgname=closure-compiler
pkgver=20170423
pkgrel=1
pkgdesc="Performs checking, instrumentation and optimizations on Javascript code."
arch=('any')
url="https://developers.google.com/closure/compiler/"
license=('APACHE')
depends=('java-runtime')
makedepends=('maven' 'git')
source=("$pkgname-$pkgver.tar.gz::https://github.com/google/$pkgname/archive/v$pkgver.tar.gz")
sha256sums=('0ee7b88ed2955b622eaa038bece283e28d0fb5abebfbb80871fc3d0353f0000b')

LANG='en_US.UTF-8'

build() {
	cd "$pkgname-$pkgver"

	mvn -DskipTests
}

#check() {
	#cd "$pkgname-$pkgver"

	#ant test
#}

package() {
	cd "$pkgname-$pkgver"

    install -Dm644 target/closure-compiler-1.0-SNAPSHOT.jar \
        "$pkgdir/usr/share/java/closure-compiler/closure-compiler.jar"
    install -Dm644 target/closure-compiler-linter-1.0-SNAPSHOT.jar \
        "$pkgdir/usr/share/java/closure-compiler/closure-compiler-linter.jar"
	install -dm755 $pkgdir/usr/bin
	echo '#!/bin/sh
	"$JAVA_HOME/bin/java" -jar /usr/share/java/closure-compiler/closure-compiler.jar $@' > "$pkgdir/usr/bin/closure-compiler"
	chmod +x "$pkgdir/usr/bin/closure-compiler"
	echo '#!/bin/sh
	"$JAVA_HOME/bin/java" -jar /usr/share/java/closure-compiler/closure-compiler-linter.jar $@' > "$pkgdir/usr/bin/closure-compiler-linter"
	chmod +x "$pkgdir/usr/bin/closure-compiler-linter"
}

