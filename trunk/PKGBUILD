# Maintainer: BlackEagle < ike DOT devolder AT gmail DOT com >
# Contributor: Jarek Sedlacek <jareksedlacek@gmail.com>

pkgname=php-mongo
pkgver=1.4.5
pkgrel=1
pkgdesc="Officially supported PHP driver for MongoDB"
arch=("i686" "x86_64")
url="http://www.mongodb.org/display/DOCS/PHP+Language+Center"
license=("APACHE")
depends=("php")
backup=("etc/php/conf.d/mongo.ini")
source=(
	"http://pecl.php.net/get/mongo-$pkgver.tgz"
	"mongo.ini"
)

build() {
	cd mongo-$pkgver
	phpize
	./configure --prefix=/usr --enable-mongo
}

package() {
	cd mongo-$pkgver
	make INSTALL_ROOT="$pkgdir" install
	install -Dm644 "$srcdir/mongo.ini" "$pkgdir/etc/php/conf.d/mongo.ini"
}
sha256sums=('45b20d4fc37e2ce1bc85dfb79418993ecfe61c519d6ad24e7d28cb4e1b380a55'
            'c89685eee842d5c3a85149a5bb8e310e62bf1a17f94183bb66401593ab2b191b')
