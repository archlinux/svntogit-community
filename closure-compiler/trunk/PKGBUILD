# $Id$
# Maintainer: BlackEagle < ike DOT devolder AT gmail DOT com >
# Contributor: Bram Schoenmakers <me@bramschoenmakers.nl>
pkgname=closure-compiler
pkgver=20160619
pkgrel=1
pkgdesc="Performs checking, instrumentation and optimizations on Javascript code."
arch=('any')
url="https://developers.google.com/closure/compiler/"
license=('APACHE')
depends=('java-runtime')
makedepends=('apache-ant' 'git')
source=("$pkgname-$pkgver.tar.gz::https://github.com/google/$pkgname/archive/v$pkgver.tar.gz")
sha256sums=('6a0fa503fcfd8bef1ef3d136a357fc14ba39d1aff24125b38aa0e457f6797340')

LANG='en_US.UTF-8'

build() {
	cd "$pkgname-$pkgver"

	ant jar
}

check() {
	cd "$pkgname-$pkgver"

	ant test
}

package() {
	cd "$pkgname-$pkgver"

	install -m755 -D build/compiler.jar "$pkgdir/usr/share/java/closure-compiler/closure-compiler.jar"
	mkdir $pkgdir/usr/bin
	echo '#!/bin/sh
	"$JAVA_HOME/bin/java" -jar /usr/share/java/closure-compiler/closure-compiler.jar $@' > "$pkgdir/usr/bin/closure"
	chmod +x "$pkgdir/usr/bin/closure"
}

