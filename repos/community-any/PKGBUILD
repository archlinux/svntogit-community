# Maintainer: Jerome Leclanche <jerome@leclan.ch>

pkgname=ttf-roboto-mono
pkgver=3.000
pkgrel=1
_commit="4df0b673c9b316ad5e8de8fa70b0768ab66c87d6"  # Latest commit touching the robotomono tree
pkgdesc="A monospaced addition to the Roboto type family."
arch=("any")
url="https://fonts.google.com/specimen/Roboto+Mono"
license=("Apache")
source=(
	"https://github.com/google/fonts/raw/$_commit/apache/robotomono/LICENSE.txt"
	"https://github.com/google/fonts/raw/$_commit/apache/robotomono/static/RobotoMono-Bold.ttf"
	"https://github.com/google/fonts/raw/$_commit/apache/robotomono/static/RobotoMono-BoldItalic.ttf"
	"https://github.com/google/fonts/raw/$_commit/apache/robotomono/static/RobotoMono-Italic.ttf"
	"https://github.com/google/fonts/raw/$_commit/apache/robotomono/static/RobotoMono-Light.ttf"
	"https://github.com/google/fonts/raw/$_commit/apache/robotomono/static/RobotoMono-LightItalic.ttf"
	"https://github.com/google/fonts/raw/$_commit/apache/robotomono/static/RobotoMono-Medium.ttf"
	"https://github.com/google/fonts/raw/$_commit/apache/robotomono/static/RobotoMono-MediumItalic.ttf"
	"https://github.com/google/fonts/raw/$_commit/apache/robotomono/static/RobotoMono-Regular.ttf"
	"https://github.com/google/fonts/raw/$_commit/apache/robotomono/static/RobotoMono-Thin.ttf"
	"https://github.com/google/fonts/raw/$_commit/apache/robotomono/static/RobotoMono-ThinItalic.ttf"
)
sha256sums=(
	"cfc7749b96f63bd31c3c42b5c471bf756814053e847c10f3eb003417bc523d30"
	"3c669d2987b72e83a924460900aec74448661d857d4de7076dfd08e931887db1"
	"f11c756558506d22b4f1244b03cfe77dd83ddf37fa334915c1f5107ea99002bd"
	"a1c3d85c3e9fd456cca6c79d65701ee549ecdeb628bb4578ff0a9290c6a67453"
	"4f1220ab0b472ddaa9c7cb0057639ca685b6fab04aa85d9e130191970fa3557c"
	"f231472b7748d96838a3586e4dedd6950799b1251b205af208fa7077e9861df6"
	"0c4e5c4d4c3c37ca47cb4047ce8821965c8fbe51884d5b0098c79c7afa6e6ab0"
	"0187ef04f288eaecdd4566732e2fad5f1ad1167298ed187a4f26beb061336ecb"
	"7432e74ff02682c6e207be405f00381569ec96aa247d232762fe721ae41b39e2"
	"63d0d03071c90ec5895ccc976eb54b14707efb6d84a05b8f19a34965ae2e31cb"
	"1cf59149df39277adf11db75b271012d6c0c73cca01967db9e24cb9a8fe4ceed"
)

package() {
	install -d "$pkgdir/usr/share/fonts/TTF/"
	install -m644 "$srcdir/"*.ttf "$pkgdir/usr/share/fonts/TTF/"
	install -D -m644 "$srcdir/LICENSE.txt" "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}

